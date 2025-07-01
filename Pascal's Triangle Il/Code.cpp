class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int pascal[rowIndex + 1][rowIndex + 1];
        vector<int> result(rowIndex + 1);

        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    pascal[i][j] = 1;
                else
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];

                if (i == rowIndex) {
                    result[j] = pascal[i][j];
                }
            }
        }
        return result;
    }
};
