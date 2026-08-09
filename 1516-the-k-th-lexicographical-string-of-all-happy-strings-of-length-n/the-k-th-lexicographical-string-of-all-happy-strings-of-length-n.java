class Solution {
    private String result = "";

    public String getHappyString(int n, int k) {
        StringBuilder current = new StringBuilder();
        int[] index = {0};
        generate(n, k, current, index);
        return result;
    }

    private void generate(int n, int k, StringBuilder current, int[] index) {
        if (!result.isEmpty()) return;

        if (current.length() == n) {
            index[0]++;
            if (index[0] == k) {
                result = current.toString();
            }
            return;
        }

        for (char c = 'a'; c <= 'c'; c++) {
            if (current.length() > 0 && current.charAt(current.length() - 1) == c) continue;
            current.append(c);
            generate(n, k, current, index);
            if (!result.isEmpty()) return;
            current.deleteCharAt(current.length() - 1);
        }
    }
}