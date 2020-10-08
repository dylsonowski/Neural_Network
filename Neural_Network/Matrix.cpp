#include <random>
#include "Matrix.h"

namespace utilities {
	namespace math {
		Matrix::Matrix(unsigned int row, unsigned int col, bool randFill) : _rowNumber(row), _colNumber(col) {

			if (randFill) {

				std::random_device device;
				std::mt19937 generator(device());
				std::uniform_real_distribution<> distribution(-1, 1);

				for (int x = 0; x < row; x++) {
					std::vector<double> temp;
					for (int y = 0; y < col; y++) {

						temp.push_back(distribution(generator));
					}
					_matrix.push_back(temp);
				}
			}
			else {

				for (int x = 0; x < row; x++) {
					std::vector<double> temp;
					for (int y = 0; y < col; y++) {

						temp.push_back(0);
					}
					_matrix.push_back(temp);
				}
			}
		}

		Matrix::Matrix(unsigned int row, unsigned int col, double value) : _rowNumber(row), _colNumber(col) {

			for (int x = 0; x < row; x++) {
				std::vector<double> temp;
				for (int y = 0; y < col; y++) {

					temp.push_back(value);
				}
				_matrix.push_back(temp);
			}
		}

		Matrix::Matrix(const Matrix& other) {

			_rowNumber = other.GetRowNumber();
			_colNumber = other.GetColumnNumber();
			_matrix.clear();
			for (int x = 0; x < other.GetRowNumber(); x++) {
				std::vector<double> temp;
				for (int y = 0; y < other.GetColumnNumber(); y++) {

					temp.push_back(other.GetValue(x, y));
				}
				_matrix.push_back(temp);
			}
		}

		void Matrix::SetValue(unsigned int rowIt, unsigned int colIt, double value)	{

			try {

				if (rowIt > GetRowNumber() || colIt > GetColumnNumber())
					throw 50;

				_matrix[rowIt][colIt] = value;
			}
			catch (int error) {

				printf("ERROR%d: This matrix ho not have that many columns/rows!\n", error);
			}
		}
	}
}