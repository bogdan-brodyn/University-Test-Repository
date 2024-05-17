namespace BubbleSort;

/// <summary>
/// Represents class with sort method implemented by default bubble sort.
/// </summary>
public static class BubbleSort
{
    /// <summary>
    /// Sorts IList collection.
    /// </summary>
    /// <typeparam name="T">Collection items type.</typeparam>
    /// <param name="list">Collection to be sorted.</param>
    /// <param name="comparer">Collection items comparer.</param>
    public static void Sort<T>(IList<T> list, Comparer<T> comparer)
    {
        if (list is null || comparer is null)
        {
            throw new NullReferenceException("Arguments must not be null references.");
        }

        for (var i = 0; i < list.Count; ++i)
        {
            for (var j = 1; j < list.Count - i; ++j)
            {
                if (comparer.Compare(list[j - 1], list[j]) > 0)
                {
                    (list[j], list[j - 1]) = (list[j - 1], list[j]);
                }
            }
        }
    }
}
