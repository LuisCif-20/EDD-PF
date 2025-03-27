template <typename T>
class BinaryInsertionSort {
    public:
        static void sort(vector<T>& arr);
    private:
        static int binarySearch(vector<T>& arr, T key, int left, int right);
};