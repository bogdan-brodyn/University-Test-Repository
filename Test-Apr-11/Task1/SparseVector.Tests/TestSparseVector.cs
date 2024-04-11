namespace SparseVector.Tests;

public class TestSparseVector
{
    [SetUp]
    public void Setup()
    {
    }

    [Test]
    public void TestAreVectorsEqual()
    {
        SparseVector vector = new ([0, 1, 0, 5, 4]);
        SparseVector sameVector = new ([0, 1, 0, 5, 4]);
        Assert.That(vector.AreVectorsEqual(sameVector), Is.EqualTo(true));
    }

    [Test]
    public void TestAdd_WithCorrectInputData_ShouldReturnExpectedResult()
    {
        SparseVector sparseVectorToAddTo = new ([0, 1, 0, 5, 4]);
        SparseVector sparseVectorToBeAdded = new ([0, 0, 6, 5, -3]);
        SparseVector expectedResult = new ([0, 1, 6, 10, 1]);
        sparseVectorToAddTo.Add(sparseVectorToBeAdded);
        Assert.That(sparseVectorToAddTo.AreVectorsEqual(expectedResult), Is.EqualTo(true));
    }
}