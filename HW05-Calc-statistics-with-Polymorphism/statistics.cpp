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
	Mean() : m_count {0},
			 m_sum{0} {
	}

	void update(double next) override {
		m_count++; 
	    // m_mean= ((m_count - 1) * m_mean + next) / (m_count); // Calc1 рассчитываем, не накапливая сумму
		m_sum+= next; // Calc2 когда копим сумму 
	}

	double eval() const override {
		// return m_mean; // Calc1 возвращаем
		return m_sum / m_count; // Calc2 возвращаем
	}

	const char * name() const override {
		return "mean";
	}

private:
	int m_count;
	double m_sum;
};	// среднеарифметическое

class Std : public IStatistics {	// среднеквадратическое отклонение
public:
	Std() : m_count{0},
			m_sum{0},
			m_sqrsum{0} {
	}

	void update(double next) override {
		m_count++; 
		m_sum+= next;
		m_sqrsum+= next * next;
	}

	double eval() const override {
		return sqrt((m_sqrsum - m_sum * m_sum / m_count) / (m_count - 1));
	}

	const char * name() const override {
		return "std";
	}

private:
	int m_count;
	double m_sum;
	double m_sqrsum;
};	// среднеквадратическое отклонение

class Pct : public IStatistics {	// Процентиль
public:
	Pct(double pct_score) : m_count{0}, m_elem{} {
		m_pct_score = pct_score;
	}

	void update(double next) override {
		m_count++; 
		m_elem.push_back(next);
		std::sort(m_elem.begin(), m_elem.end());
	}

	double eval() const override {
		return m_elem[(int)(m_pct_score * m_count / 100)];
	}

	const char * name() const override {
		return "pct";
	}

private:
	int m_count;
	std::vector<double> m_elem;
	double m_pct_score = 0;
}; // Процентиль

int main() {

	const size_t statistics_count = 6;
	IStatistics* statistics[statistics_count];

		statistics[0] = new Min{};
		statistics[1] = new Max{};
		statistics[2] = new Mean{};
		statistics[3] = new Std{};
		statistics[4] = new Pct(90);
		statistics[5] = new Pct(95);

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






// хвост рекурсии
// template <class OutIter>
// void fill(OutIter) { }

// template <class OutIter, class Type, class... RestTypes>
// void fill(OutIter iter) {
//     *iter = new Type{};
//     fill<OutIter, RestTypes...>(std::next(iter));
// }

// int main() {
// 	const size_t statistics_count = 6;
// 	IStatistics* statistics[statistics_count];

//     auto iter = std::begin(statistics);
//     fill<decltype(iter), Min, Max, Mean, Std, Pct90, Pct95>(iter);
//     ...
// }
