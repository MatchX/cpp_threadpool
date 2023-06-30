#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#include <windows.h>
#elif __linux__
#elif TARGET_OS_MAC
#else
#   error "Unknown compiler"
#endif

#include "threadpool.h"


class TPworker {
private:
	int m_x{ 2 };
private:
	inline int calsum(const int x, const int y = 152)
	{
		std::cout << "tdwork\n";
		//::Sleep(8000);
		//Sleep()
		return x + y;
	}
	std::vector<int> calsub(const int& x, const int& y);
	std::vector<int> vecsum(std::vector<int>& invec);
public:
	int tpooltest()
	{
		ThreadPool pool(4);
		std::vector< std::future<int> > results;

		//pool.enqueue(this->calsum());
		//auto xz = [this] {return this->calsum(); };
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);

		auto rv0 = pool.addWorkFunc([this] { return this->calsum(1, 7); });
		auto rv1 = pool.addWorkFunc([this] { return this->calsub(2, 12); });
		auto rv2 = pool.addWorkFunc([this] { return this->calsum(3, 52); });
		auto rv3 = pool.addWorkFunc([this] { return this->calsum(4, 91); });
		auto rv4 = pool.addWorkFunc([this] { return this->calsub(4, 91); });
		auto rv5 = pool.addWorkFunc([=, &vec] { return this->vecsum(vec); });

		rv0.get();
		rv1.get();
		rv2.get();
		auto flg01 = rv3.valid();
		int a = rv3.get();
		auto flg02 = rv3.valid();
		auto b = rv4.get();
		auto c = rv5.get();
		std::cout << a << std::endl;
		std::cout << b[0] << std::endl;
		//int x = rv4.get();

		int ds = 1;
		return ds;
	}
};

std::vector<int> TPworker::calsub(const int& x, const int& y)
{
	std::vector<int> vec;
	vec.push_back(x - y);
	return vec;
}

std::vector<int> TPworker::vecsum(std::vector<int>& invec)
{
	for(auto& it : invec)
	{
		it += m_x;
	}
	return invec;
}

int main()
{
	TPworker tpw;
	tpw.tpooltest();
	return 0;
}
