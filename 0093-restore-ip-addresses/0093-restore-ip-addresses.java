import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        backtrack(s, 0, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(String s, int startIndex, List<String> path, List<String> result) {
        if (path.size() == 4) {
            if (startIndex == s.length()) {
                result.add(String.join(".", path));
            }
            return;
        }

        for (int i = startIndex; i < s.length() && i < startIndex + 3; i++) {
            String segment = s.substring(startIndex, i + 1);
            if (isValid(segment)) {
                path.add(segment);
                backtrack(s, i + 1, path, result);
                path.remove(path.size() - 1);
            }
        }
    }

    private boolean isValid(String segment) {
        if (segment.length() > 1 && segment.startsWith("0")) {
            return false;
        }
        int val = Integer.parseInt(segment);
        return val >= 0 && val <= 255;
    }
}