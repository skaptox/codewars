std::vector<int> takeWhile(std::vector<int> arr, std::function<bool (int)> pred)
{
    std::vector<int> result;
    for (const auto & item : arr)
    {
      if (pred(item))
        result.push_back(item);
      else
        break;
    }
    return result;
}

/*
Here's another staple for the functional programmer. You have a sequence of values and some predicate for those values. You want to get the longest prefix of elements such that the predicate is true for each element. We'll call this the takeWhile function. It accepts two arguments. The first is the sequence of values, and the second is the predicate function. The function does not change the value of the original sequence.

std::function<bool (int)> isEven = [](int value)
{
    return abs(value) % 2 == 0;
};

std::vector<int> seq = { 2, 4, 6, 8, 1, 2, 5, 4, 3, 2 };

takeWhile(seq, pred); // -> { 2, 4, 6, 8 }

Your task is to implement the takeWhile function.

If you've got a span function lying around, this is a one-liner! Also, if you liked this problem, you'll surely love the dropWhile function.
*/
