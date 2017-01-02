#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cmath>

namespace w8 {

	template <typename T>
	class DataTable {
		std::vector<T> _xs;
		std::vector<T> _ys;
		int _FW;
		int _ND;

	public:
		DataTable(std::ifstream& in, int FW, int ND) : _FW(FW), _ND(ND) {

			T x, y;
			while (!in.eof()) {
				in >> x >> y;
				_xs.push_back(x);
				_ys.push_back(y);
			}
		}

		T mean() const {
			T sum = std::accumulate(_ys.begin(), _ys.end(), (T)0);
			T num = _ys.size();

			return sum / num;
		}

		T sigma() const {
			T mean_ = mean();
			T num = _ys.size();

			std::vector<T> diff(num);
			std::transform(_ys.begin(), _ys.end(), diff.begin(), std::bind2nd(std::minus<T>(), mean_));

			T sum_sq = std::inner_product(diff.begin(), diff.end(), diff.begin(), (T)0);
			return (T)std::sqrt(sum_sq / (num - 1));
		}

		T median() const {
			std::vector<T> sort_ = this->_ys;
			std::sort(sort_.begin(), sort_.end());
			T num = _ys.size();

			return sort_[num / 2];
		}

		void regression(T& slope, T& y_intercept) const {
			
			T sum_xy = std::inner_product(_xs.begin(), _xs.end(), _ys.begin(), (T)0);
			T sum_x = std::accumulate(_xs.begin(), _xs.end(), (T)0);
			T sum_y = std::accumulate(_ys.begin(), _ys.end(), (T)0);
			T sum_sq_x = std::inner_product(_xs.begin(), _xs.end(), _xs.begin(), (T)0);		
			T num = _ys.size();

			slope = (num * sum_xy - sum_x * sum_y) / (num * sum_sq_x - sum_x * sum_x);
			y_intercept = (sum_y - slope * sum_x) / num;
		}

		void display(std::ostream& os) const {
			os << std::setprecision(_ND) << std::fixed;
			os << std::setw(_FW) << 'x' << std::setw(_FW) << 'y' << std::endl;

			for (int i = 0; i < _xs.size(); i++) {
				os << std::setw(_FW) << _xs[i] << std::setw(_FW) << _ys[i] << std::endl;
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const DataTable& D) {
			D.display(os);
			return os;
		}
	};
}