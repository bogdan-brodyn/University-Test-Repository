namespace SparseVector;

/// <summary>
/// Sparse vector implementation (helps to save space).
/// </summary>
public class SparseVector
{
    private readonly Dictionary<int, int> sparseVector = new ();

    /// <summary>
    /// Initializes a new instance of the <see cref="SparseVector"/> class.
    /// </summary>
    /// <param name="vector">Standart vector representation by coordinates' vector.</param>
    public SparseVector(int[] vector)
    {
        for (var i = 0; i < vector.Length; ++i)
        {
            if (vector[i] != 0)
            {
                sparseVector.Add(i, vector[i]);
            }
        }
    }

    private SparseVector()
    {
    }

    /// <summary>
    /// Gets vector dimension.
    /// </summary>
    public int Dimension { get; }

    /// <summary>
    /// Check if the vector is zero vector.
    /// </summary>
    /// <returns>True if vector is zero vector, false, otherwise.</returns>
    public bool IsZeroVector() => sparseVector.Count == 0;

    /// <summary>
    /// Check if vectors are equal.
    /// </summary>
    /// <param name="otherSparseVector">Second vector to compare.</param>
    /// <returns>True if vectors are equal, false, otherwise.</returns>
    public bool AreVectorsEqual(SparseVector otherSparseVector)
    {
        if (otherSparseVector == null)
        {
            return IsZeroVector();
        }

        if (this.sparseVector.Count != otherSparseVector.sparseVector.Count)
        {
            return false;
        }

        foreach (var (coordinate, value) in otherSparseVector.sparseVector)
        {
            var wasContained = sparseVector.TryGetValue(coordinate, out var thisValue);
            if (!wasContained || thisValue != value)
            {
                return false;
            }
        }

        return true;
    }

    /// <summary>
    /// Adds input vector to this vector.
    /// </summary>
    /// <param name="sparseVectorToAdd">Vector to be added.</param>
    /// <exception cref="ArgumentException">Vectors' dimensions are not the same.</exception>
    public void Add(SparseVector sparseVectorToAdd)
    {
        ApplyOperationCoordinateWise(sparseVectorToAdd, (x, y) => x + y);
    }

    /// <summary>
    /// Substracts input vector from this vector.
    /// </summary>
    /// <param name="sparseVectorToSubstract">Vector to be substracted.</param>
    /// <exception cref="ArgumentException">Vectors' dimensions are not the same.</exception>
    public void Subtract(SparseVector sparseVectorToSubstract)
    {
        ApplyOperationCoordinateWise(sparseVectorToSubstract, (x, y) => x - y);
    }

    /// <summary>
    /// Gets scalar product of this vector and input vector.
    /// </summary>
    /// <param name="secondSparseVector">Second sparse vector to get scalar product.</param>
    /// <returns>Scalar product.</returns>
    /// <exception cref="ArgumentException">Vectors' dimensions are not the same.</exception>
    public int GetScalarProduct(SparseVector secondSparseVector)
    {
        ThrowArgumentExceptionIfDimensionsNotTheSame(secondSparseVector);
        int scalarProduct = 0;
        foreach (var (coordinate, value) in secondSparseVector.sparseVector)
        {
            var wasContained = sparseVector.TryGetValue(coordinate, out var thisValue);
            scalarProduct += thisValue * value;
        }

        return scalarProduct;
    }

    private void ApplyOperationCoordinateWise(
        SparseVector secondSparseVectorOperand,
        Func<int, int, int> operation)
    {
        ThrowArgumentExceptionIfDimensionsNotTheSame(secondSparseVectorOperand);
        foreach (var (coordinate, value) in secondSparseVectorOperand.sparseVector)
        {
            sparseVector.TryAdd(coordinate, value);
            sparseVector[coordinate] = operation(sparseVector[coordinate], value);
            if (sparseVector[coordinate] == 0)
            {
                sparseVector.Remove(coordinate);
            }
        }
    }

    private void ThrowArgumentExceptionIfDimensionsNotTheSame(
        SparseVector sparseVectorToCompareDimensions)
    {
        if (Dimension != sparseVectorToCompareDimensions.Dimension)
        {
            throw new ArgumentException("Vectors' dimensions must be the same.");
        }
    }
}
