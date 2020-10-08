#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <Windows.h>

namespace utilities {
	namespace math {
		class Matrix {

		public:
			Matrix() = delete;
			Matrix(unsigned int row, unsigned int col, bool randFill);
			Matrix(unsigned int row, unsigned int col, double value);
			Matrix(const Matrix& other);
			~Matrix() = default;

			void SetValue(unsigned int rowIt, unsigned int colIt, double value);
			inline double GetValue(unsigned int rowIt, unsigned int colIt) const { return _matrix[rowIt][colIt]; }
			inline unsigned int GetRowNumber() const { return _rowNumber; }
			inline unsigned int GetColumnNumber() const { return _colNumber; }
			std::string ToString() const {

				std::stringstream stream;
				for (int x = 0; x < _rowNumber; x++) {
					for (int y = 0; y < _colNumber; y++) {
						stream << _matrix[x][y] << " | ";
					}
					stream << "\n";
				}

				return stream.str();
			}

			inline Matrix operator*(double value) {
	
				for (int x = 0; x < this->_rowNumber; x++) {
					for (int y = 0; y < this->_colNumber; y++) {

						this->_matrix[x][y] *= value;
					}
				}
				return *this;
			}

			inline Matrix operator*(const Matrix& other) {

				try {

					if (_colNumber != other.GetRowNumber())
						throw(30);

					Matrix temp(_rowNumber, other.GetColumnNumber(), false);
					for (int x = 0; x < _rowNumber; x++) {
						for (int y = 0; y < other.GetColumnNumber(); y++) {
							double value = 0;
							for (int z = 0; z < other.GetRowNumber(); z++) {

								value += _matrix[x][z] * other.GetValue(z, y);
								temp.SetValue(x, y, value);
							}
						}
					}
					return temp;
				}
				catch (int error) {

					printf("ERROR%d: Dimensions of the matrixes are not equal!\n", error);
					system("pause");
					exit(1);
				}
			}

			inline Matrix operator~() {

				Matrix temp(_colNumber, _rowNumber, false);
				for (int x = 0; x < _rowNumber; x++) {
					for (int y = 0; y < _colNumber; y++) {

						temp.SetValue(y, x, _matrix[x][y]);
					}
				}
				return temp;
			}

			inline Matrix operator[](unsigned int iterator) {

				try {

					if (iterator > _colNumber - 1)
						throw 90;

					Matrix temp(_rowNumber, 1, false);
					for (int x = 0; x < _rowNumber; x++) {

						temp.SetValue(x, 0, _matrix[x][iterator]);
					}
					return temp;
				}
				catch (int error) {

					printf("ERROR%d: Matrix out of reach acces!\n", error);
					system("pause");
					exit(1);
				}
			}

		private:
			unsigned int _rowNumber, _colNumber;
			std::vector<std::vector<double>> _matrix;
		};

		inline std::ostream& operator<<(std::ostream& stream, const Matrix& matrix) {
			return stream << matrix.ToString();
		}
	}
}

