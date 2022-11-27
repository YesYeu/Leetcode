#include <iostream>
#include <vector>
using namespace std;

// class Solution0
//{
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         int num_range = 20001;
//         vector<int> accur_stat(num_range, 0);
//         int offset = 10000;
//         for (auto i : nums)
//         {
//             accur_stat[i + offset]++;
//         }
//
//         int order = 0;
//         int index = 0;
//         for (vector<int>::size_type j = num_range; j > 0; j--)
//         {
//             if ((order += accur_stat[j - 1]) >= k)
//             {
//                 index = j - 1;
//                 break;
//             }
//         }
//
//         return index - offset;
//     }
// };

// select based on quicksort
class Solution1
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        quicksort(nums.begin(), nums.end());
        return nums[k - 1];
    }

    inline void quicksort(vector<int>::iterator p, vector<int>::iterator q)
    {
        if (p < q - 1)
        {
            vector<int>::iterator index = partition(p, q);
            quicksort(p, index);
            quicksort(index + 1, q);
        }
    }

    inline vector<int>::iterator partition(vector<int>::iterator p, vector<int>::iterator q)
    {
        int r = *(q - 1);
        vector<int>::iterator i = p, j = p;
        while (j < q)
        {
            if (*j >= r)
            {
                int temp = *j;
                *j = *i;
                *i++ = temp;
            }
            j++;
        }
        return (i - 1);
    }
};

// select based on ramdomized quicksort
class Solution2
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return select(nums, 0, nums.size(), k);
    }

    inline int select(vector<int> &nums, int p, int q, int index)
    {
        if (p == q - 1)
            return nums[p];
        int k = randomized_partition(nums, p, q);
        int l = k - p + 1;
        if (l == index)
            return nums[k];
        if (index < l)
            return select(nums, p, k, index);
        else
            return select(nums, k + 1, q, index - l);
    }

    inline int randomized_partition(vector<int> &nums, int p, int q)
    {
        int x = (rand() % (q - p)) + p;
        int temp0 = nums[x];
        nums[x] = nums[q - 1];
        nums[q - 1] = temp0;

        int r = nums[q - 1];
        int i = p, j = p;
        while (j < q)
        {
            if (nums[j] >= r)
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i++] = temp;
            }
            j++;
        }
        return (i - 1);
    }
};

// select based on ramdomized quicksort(iterator is uesed)
class Solution3
{
public:
    typedef vector<int>::iterator user_ptr;

    int findKthLargest(vector<int> &nums, int k)
    {
        return select(nums, nums.begin(), nums.end(), k);
    }

    inline int select(vector<int> &nums, user_ptr p, user_ptr q, int index)
    {
        if (p == q - 1)
            return *p;
        user_ptr k = randomized_partition(nums, p, q);
        int l = k - p + 1;
        if (l == index)
            return *k;
        if (index < l)
            return select(nums, p, k, index);
        else
            return select(nums, k + 1, q, index - l);
    }

    inline user_ptr randomized_partition(vector<int> &nums, user_ptr p, user_ptr q)
    {
        user_ptr x = (rand() % (q - p)) + p;
        int temp0 = *x;
        *x = *(q - 1);
        *(q - 1) = temp0;

        int r = *(q - 1);
        user_ptr i = p, j = p;
        while (j < q)
        {
            if (*j >= r)
            {
                int temp = *j;
                *j = *i;
                *i++ = temp;
            }
            j++;
        }
        return (i - 1);
    }
};


// select algorithm based on heap sort
class Solution4
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        heapsize = nums.size();
        Build_Heap(nums);

        for (int i = 1; i < k + 1; i++)
        {
            int temp = nums[heapsize - 1];
            nums[heapsize - 1] = nums[0];
            nums[0] = temp;
            heapsize--;
            Max_Heapify(nums, 0);
        }
        return nums[nums.size() - k];
    }

    inline int parent(int k) { return (k - 1) / 2; }
    inline int leftchild(int k) { return (2 * k + 1); }
    inline int rightchild(int k) { return (2 * k + 2); }

    void Max_Heapify(vector<int> &nums, int k)
    {
        int i = k;
        int obj = nums[k];
        while (i < heapsize / 2)
        {
            int largest = obj, largest_index = i;
            int left = leftchild(i);
            int right = rightchild(i);

            if(left <heapsize && nums[left] > largest)
            {
                largest_index = left;
                largest = nums[left];
            }
            if(right < heapsize && nums[right] > largest)
            {
                largest_index = right;
                largest = nums[right];
            }
            if (largest_index != i)
            {
                nums[i] = largest;
                i = largest_index;
            }
            else
                break;
        }
        nums[i] = obj;
    }

    void Build_Heap(vector<int> &nums)
    {
        for (int i = heapsize / 2 - 1; i >= 0; i--)
            Max_Heapify(nums, i);
    }
    int heapsize = 0;
};

// select algorithm based on heap sort(using recurrence)
class Solution5
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        heapsize = nums.size();
        Build_Heap(nums);

        for (int i = 1; i < k + 1; i++)
        {
            int temp = nums[heapsize - 1];
            nums[heapsize - 1] = nums[0];
            nums[0] = temp;
            heapsize--;
            Max_Heapify(nums, 0);
        }
        return nums[nums.size() - k];
    }

    inline int parent(int k) { return (k - 1) / 2; }
    inline int leftchild(int k) { return (2 * k + 1); }
    inline int rightchild(int k) { return (2 * k + 2); }

    void Max_Heapify(vector<int> &nums, int k)
    {
        int largest = k;
        int left = leftchild(k);
        int right = rightchild(k);
        if(left < heapsize && nums[left] > nums[largest])
            largest = left;
        if(right < heapsize && nums[right] > nums[largest])
            largest = right;
        if(largest != k)
        {
            swap(nums[k], nums[largest]);
            Max_Heapify(nums,largest);
        }
    }

    void Build_Heap(vector<int> &nums)
    {
        for (int i = heapsize / 2 - 1; i >= 0; i--)
            Max_Heapify(nums, i);
    }
    int heapsize = 0;
};
