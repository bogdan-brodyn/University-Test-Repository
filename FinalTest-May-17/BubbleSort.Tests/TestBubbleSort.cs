namespace BubbleSort.Tests;

public class TestBubbleSort
{
    [Test]
    public void TestBubbleSort_WithIntegerStandartUseCase_ChangesMustBeExpected()
    {
        // Arrange
        var testCase = new int[] { 15, 7, -1024, 512, -0, 0, 1, -10, 2, 5, 5, 1, 1 };
        var comparer = Comparer<int>.Default;

        // Act
        BubbleSort.Sort(testCase, comparer);

        // Assert
        var expectedResult = new int[] { -1024, -10, 0, 0, 1, 1, 1, 2, 5, 5, 7, 15, 512 };
        var actualResult = testCase;
        CollectionAssert.AreEqual(expected: expectedResult, actual: actualResult);
    }

    [Test]
    public void TestBubbleSort_WithEmptyIntegerArray()
    {
        // Arrange
        var testCase = Array.Empty<int>();
        var comparer = Comparer<int>.Default;

        // Act
        BubbleSort.Sort(testCase, comparer);

        // Assert
        var expectedResult = Array.Empty<int>();
        var actualResult = testCase;
        CollectionAssert.AreEqual(expected: expectedResult, actual: actualResult);
    }

    [Test]
    public void TestBubbleSort_WithStringStandartUseCase_ChangesMustBeExpected()
    {
        // Arrange
        var testCase = new string[] { "a", "b", "ab", "aaa", "aa", "bcdf", string.Empty };
        var comparer = Comparer<string>.Default;

        // Act
        BubbleSort.Sort(testCase, comparer);

        // Assert
        var expectedResult = new string[] { string.Empty, "a", "aa", "aaa", "ab", "b", "bcdf" };
        var actualResult = testCase;
        CollectionAssert.AreEqual(expected: expectedResult, actual: actualResult);
    }

    [Test]
    public void TestBubbleSort_WithEmptyStringArray()
    {
        // Arrange
        var testCase = Array.Empty<string>();
        var comparer = Comparer<string>.Default;

        // Act
        BubbleSort.Sort(testCase, comparer);

        // Assert
        var expectedResult = Array.Empty<string>();
        var actualResult = testCase;
        CollectionAssert.AreEqual(expected: expectedResult, actual: actualResult);
    }

    [Test]
    public void TestBubbleSort_WithNullReferences_MustThrowNullReferenceException()
    {
        Assert.Throws<NullReferenceException>(
            () => BubbleSort.Sort<object>(null!, null!));
    }
}
