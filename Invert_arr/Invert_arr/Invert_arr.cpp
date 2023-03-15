#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>

int const N = 4;
int det = 0;

int copy_to_matrix(int matrix[N][N], std::istream& file)
{
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			file >> matrix[i][j];
		}
	}
	return 0;
}

int find_det(int matrix[N][N])
{
	det = ((matrix[1][1] * matrix[2][2] * matrix[3][3]) + (matrix[1][2] * matrix[2][3] * matrix[3][1]) + (matrix[2][1] * matrix[3][2] * matrix[1][3]) -
		(matrix[3][2] * matrix[2][3] * matrix[1][1]) - (matrix[2][1] * matrix[3][3] * matrix[1][2]) - (matrix[1][3] * matrix[2][2] * matrix[3][1]));

	return det;
}

int find_matrix_minor(int matrix[N][N], int matrix_minor[N][N])
{
	matrix_minor[1][1] = ((matrix[2][2] * matrix[3][3]) - (matrix[2][3] * matrix[3][2]));
	matrix_minor[1][2] = -((matrix[2][1] * matrix[3][3]) - (matrix[2][3] * matrix[3][1]));
	matrix_minor[1][3] = ((matrix[2][1] * matrix[3][2]) - (matrix[2][2] * matrix[3][1]));
	matrix_minor[2][1] = -((matrix[1][2] * matrix[3][3]) - (matrix[1][3] * matrix[3][2]));
	matrix_minor[2][2] = ((matrix[1][1] * matrix[3][3]) - (matrix[1][3] * matrix[3][1]));
	matrix_minor[2][3] = -((matrix[1][1] * matrix[3][2]) - (matrix[1][2] * matrix[3][1]));
	matrix_minor[3][1] = ((matrix[1][2] * matrix[2][3]) - (matrix[1][3] * matrix[2][2]));
	matrix_minor[3][2] = -((matrix[1][1] * matrix[2][3]) - (matrix[1][3] * matrix[2][1]));
	matrix_minor[3][3] = ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]));

	return 0;
}

int find_matrix_transp(int matrix_minor[N][N])
{
	int matrix_temp[N][N];

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			matrix_temp[i][j] = matrix_minor[j][i];
		}
	}


	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			matrix_minor[i][j] = matrix_temp[i][j];
		}
	}

	return 0;
}

int find_matrix_invert(int matrix_minor[N][N], int det, std::ostream& output)
{
	std::cout << "matrix invert equals:" << std::endl;

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			int temp;
			temp = matrix_minor[i][j];
			matrix_minor[i][j] = temp / det;
			output << matrix_minor[i][j] << ' ';
		}
		output << std::endl;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}

	std::string file_name = argv[1];
	std::ifstream input_file(file_name);

	int matrix[N][N] = { 0 };
	int matrix_minor[N][N] = { 0 };

	if (!input_file.is_open())
	{
		std::cout << "There is a problem with opening file!" << std::endl;
		return 1;
	}

	else
	{
		copy_to_matrix(matrix, input_file);

		if (find_det(matrix) == 0)
		{
			std::cout << "Determinate equals:0. There's no solution!" << std::endl;
		}
		else
		{
			//std::cout << "Determinate equals: " << det << std::endl;
			find_matrix_minor(matrix, matrix_minor);

			find_matrix_transp(matrix_minor);

			find_matrix_invert(matrix_minor, det, std::cout);
		}
	}
	return 0;
}