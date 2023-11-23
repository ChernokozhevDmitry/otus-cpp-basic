#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <math.h>


class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {	// минимальное
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	} 

private:
	double m_min;
}; // минимальное

class Max : public IStatistics {	// максимальное
public:
	Max() : m_max{-std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
}; // максимальное

class Mean : public IStatistics {	// среднеарифметическое
public:
	Mean() : m_mean{0},
			 m_count {0} {
	}

	void update(double next) override {
		m_count++; 
		m_mean= ((m_count - 1) * m_mean + next) / (m_count);
	}

	double eval() const override {
		return m_mean;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double m_mean;
	int m_count;
};	// среднеарифметическое

class Std : public IStatistics {	// среднеквадратическое отклонение
public:
	Std() : m_std{0},
			m_count{0},
			m_sum{0},
			m_sqrsum{0} {
	}

	void update(double next) override {
		m_count++; 
		m_sum+= next;
		m_sqrsum+= next * next;
		if (m_count > 1) {
			m_std = sqrt((m_sqrsum - m_sum * m_sum / m_count) / (m_count - 1));
		}
	}

	double eval() const override {
		return m_std;
	}

	const char * name() const override {
		return "std";
	}

private:
	double m_std;
	int m_count;
	double m_sum;
	double m_sqrsum;
};	// среднеквадратическое отклонение

class Pct90 : public IStatistics {	// Процентиль 90
public:
	Pct90() : m_pct90{0},
			  m_count{0},
			  m_elem{} {
	}

	void update(double next) override {
		m_count++; 
		m_elem.push_back(next);
		std::sort(m_elem.begin(), m_elem.end());
		m_pct90 = m_elem[(int)(0.9 * m_count)];
	}

	double eval() const override {
		return m_pct90;
	}

	const char * name() const override {
		return "pct90";
	}

private:
	double m_pct90;
	int m_count;
	std::vector<double> m_elem;
}; // Процентиль 90

class Pct95 : public IStatistics {	// Процентиль 95
public:
	Pct95() : m_pct95{0},
			  m_count{0},
			  m_elem{} {
	}

	void update(double next) override {
		m_count++; 
		m_elem.push_back(next);
		std::sort(m_elem.begin(), m_elem.end());
		m_pct95 = m_elem[(int)(0.95 * m_count)];
	}

	double eval() const override {
		return m_pct95;
	}

	const char * name() const override {
		return "pct95";
	}

private:
	double m_pct95;
	int m_count;
	std::vector<double> m_elem;
}; // Процентиль 95

int main() {

	const size_t statistics_count = 6;
	IStatistics* statistics[statistics_count];


//  ВОПРОС: Не дожал как это не копипастить, а тоже бы в цикл инициализацию.
//			Названия классов разное, не соображу как, на форумах стали предлагать с шаблонами разные действия,
// 	        но пока тяжеловато это осилить (в конце файла там в комментах).
//          Есть ли какой-то изящный и +- понятный на данном этапе обучения способ не копипастить тут?
		statistics[0] = new Min{};
		statistics[1] = new Max{};
		statistics[2] = new Mean{};
		statistics[3] = new Std{};
		statistics[4] = new Pct90{};
		statistics[5] = new Pct95{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}








// template <typename... Args>
// struct TypeList {};

// template <typename F, std::size_t... I, typename... Args>
// constexpr auto forEachImpl(F&& f, std::index_sequence<I...>, TypeList<Args...>) {
//   (f(I, std::type_identity<Args>()), ...);
// };
// template <typename F, typename... Args>
// constexpr auto forEach(TypeList<Args...> types, F&& f) {
//   return forEachImpl(std::forward<F>(f), std::make_index_sequence<sizeof...(Args)>(), types);
// };


// int main() {
//   forEach(TypeList<int, std::string>(), []<typename T>(std::size_t i, std::type_identity<T>){
//     std::cout << typeid(T).name() << " on index " << i << std::endl;
//   });








// template<typename... Args>
// std::vector<const char*> getDerivedTypes() {
// return { typeid(Args).name()... };

// }

// 	auto derivedTypes = getDerivedTypes<Min, Max, Mean, Std, Pct90, Pct95>();

// 	for (const auto& type : derivedTypes) {
// 		std::cout << type << '\n';
// 	    // statistics[0] = new type{}; // ??? expected a type specifier
// 	    ClassOld = new type{}; // ??? expected a type specifier Что делать тут ???
// 	}

