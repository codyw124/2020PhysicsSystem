//Cody Ware
//6/30/19

#include "../headers/TransformTests.h"

void TransformTests::runAllTests()
{
	T1_testBigFive();
	T2_testSwitchMajors();
	T3_testGetSetTranslate();
	T4_testGetSetScale();
	T5_testGetSetXYZAxis();
	T6_testRotate();
	cout << "All Transform Tests Passed\n";
}

void TransformTests::T1_testBigFive()
{
	//default constructor
	Transform x;

	assert(x.isRowMajor(), "defaults to row major");
	Transform a;

	a.toOtherMajor();

	//copy constructor
	Transform y(a);

	assert(!y.isRowMajor(), "test that copy constructor copies major");

	//move constructor
	Transform z(std::move(x));

	//operator=
	x=a;

	//move operator
	z = std::move(a);
}

void TransformTests::T2_testSwitchMajors()
{
	Transform a;

	a.toOtherMajor();

	assert(!a.isRowMajor(), "test that changing majors works");
}

void TransformTests::T3_testGetSetTranslate()
{
	Transform a;

	Vector3 x(1, 2, 3);

	a.setTranslate(x);

	assert(a.getTranslate() == x, "make sure that the transform was set when row major");

	a.toOtherMajor();

	assert(a.getTranslate() == x, "changing majors to column major must maintain transform");

	Transform b;

	b.toOtherMajor();

	b.setTranslate(x);

	assert(b.getTranslate() == x, "make sure that transform is set when column major");

	assert(b.getTranslate() == x, "changing majors to row major must maintain transform");
}

void TransformTests::T4_testGetSetScale()
{
	Transform a;

	Vector3 x(1, 2, 3);

	a.setScale(x);

	assert(a.getScale() == x, "make sure that the scale was set in row major");

	a.toOtherMajor();

	assert(a.getScale() == x, "changing majors to column major must maintain scale");

	Transform b;

	b.toOtherMajor();

	b.setScale(x);

	assert(b.getScale() == x, "make sure that setting scale in column major works");

	b.toOtherMajor();

	assert(b.getScale() == x, "make sure that changing major to row major maintains the scale");
}

void TransformTests::T5_testGetSetXYZAxis()
{
	Transform rowMajorTest;

	Vector3 rowMajorTestVector(1, 2, 3);
	
	//xaxis
	rowMajorTest.setXAxis(rowMajorTestVector);

	assert(rowMajorTest.getXAxis() == rowMajorTestVector, "make sure xaxis get set");

	//yaxis
	rowMajorTestVector *= 2;
	rowMajorTest.setYAxis(rowMajorTestVector);

	assert(rowMajorTest.getYAxis() == rowMajorTestVector, "make sure y axis gets set");

	//zaxis
	rowMajorTestVector *= 2;
	rowMajorTest.setZAxis(rowMajorTestVector);

	assert(rowMajorTest.getZAxis() == rowMajorTestVector, "make sure z axis gets set");

	rowMajorTest.toOtherMajor();

	assert(rowMajorTest.getZAxis() == rowMajorTestVector, "make sure z axis is maintained after changing majors");
	rowMajorTestVector /= 2;
	assert(rowMajorTest.getYAxis() == rowMajorTestVector, "make sure y axis is maintained after changing majors");
	rowMajorTestVector /= 2;
	assert(rowMajorTest.getXAxis() == rowMajorTestVector, "make sure x axis is maintained after changing majors");

	//test again but start with a column major
	Transform columnMajorTest;
	columnMajorTest.toOtherMajor();

	Vector3 columnMajorTestVector(1, 2, 3);

	//xaxis
	columnMajorTest.setXAxis(columnMajorTestVector);

	assert(columnMajorTest.getXAxis() == columnMajorTestVector, "make sure xaxis get set");

	//yaxis
	columnMajorTestVector *= 2;
	columnMajorTest.setYAxis(columnMajorTestVector);

	assert(columnMajorTest.getYAxis() == columnMajorTestVector, "make sure y axis gets set");

	//zaxis
	columnMajorTestVector *= 2;
	columnMajorTest.setZAxis(columnMajorTestVector);

	assert(columnMajorTest.getZAxis() == columnMajorTestVector, "make sure z axis gets set");

	columnMajorTest.toOtherMajor();

	assert(columnMajorTest.getZAxis() == columnMajorTestVector, "make sure z axis is maintained after changing majors");
	columnMajorTestVector /= 2;
	assert(columnMajorTest.getYAxis() == columnMajorTestVector, "make sure y axis is maintained after changing majors");
	columnMajorTestVector /= 2;
	assert(columnMajorTest.getXAxis() == columnMajorTestVector, "make sure x axis is maintained after changing majors");

}

void TransformTests::T6_testRotate()
{

	Matrix expectedAfterRotating45degrees;
	expectedAfterRotating45degrees[0][0] = 0.52532198881772973;
	expectedAfterRotating45degrees[0][1] = 0.85090352453411844;
	expectedAfterRotating45degrees[1][0] = -0.85090352453411844;
	expectedAfterRotating45degrees[1][1] = 0.52532198881772973;

	Transform x;

	Matrix actualAfter45DegreeZRotate = x.rotateZ(45);

	assert(actualAfter45DegreeZRotate == expectedAfterRotating45degrees, "rotating Z 45 degrees doesnt work as expected");
}