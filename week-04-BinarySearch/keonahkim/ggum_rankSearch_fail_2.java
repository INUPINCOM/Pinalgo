import java.util.List;
import java.util.ArrayList;

class Solution {
    public int[] solution(String[] info, String[] query) {

        List<Integer> answer = new ArrayList<>();

        for (String s : query) {
            int count = 0;
            String queryScoreStr = s.split(" ")[7];
            Integer queryScore = Integer.valueOf(queryScoreStr);

            String regex = ".*"
                    + s.replaceAll("- ", "")
                    .replaceAll("and ", "")
                    .replace(queryScoreStr, "")
                    .replaceAll(" ", ".*");

            int k = 0;
            for (String i : info) {
                Integer score = Integer.valueOf(i.split(" ")[4]);

                if (i.matches(regex) && score >= queryScore) {
                    count++;
                }
            }

            answer.add(count);
        }

        return answer.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }
}
