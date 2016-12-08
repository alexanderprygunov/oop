#include "stdafx.h"
#include "../vector/VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

bool VerifyProcessVectory(vector<double> originalVector, vector<double> expectedResult)
{
	ProcessVector(originalVector);
	return VectorsAreEqual(originalVector, expectedResult);
}

// 4. Требуется разделить элементы массива на половину максимального элемента

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	// Создает пустой вектор из пустого вектора
	BOOST_AUTO_TEST_CASE(dont_change_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	// Не меняет вектор максимальное значение max=0
	BOOST_AUTO_TEST_CASE(does_not_divide_vector_in_which_maximum_element_this_zero)
	{
		BOOST_CHECK(VerifyProcessVectory({-17.0, -8.0, 0.0 }, {-17.0, -8.0, 0.0 }));
	}

	// Делит элменты вектора на половину максимального значения
	BOOST_AUTO_TEST_CASE(dividing_every_vectors_element_by_half_max_element)
	{
		BOOST_CHECK(VerifyProcessVectory({ -8.0, 4.0, 3.0 }, { -4.0, 2.0, 1.5 }));
	}

BOOST_AUTO_TEST_SUITE_END()