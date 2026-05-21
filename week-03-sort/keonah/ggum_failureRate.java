import java.util.List;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
import java.util.stream.Collectors;
import java.util.Comparator;

class Solution {
    public int[] solution(int N, int[] stages) {
        // 각 스테이지 별 도달한 플레이어와 머무르고 있는 플레이어를 카운트
        Map<Integer, List<Integer>> StageCountMap = new HashMap<>();

        // 초기 값 설정
        for (int i = 1; i < N + 1 ; i++) {
            StageCountMap.put(i, List.of(0, 0));
        }

        // 스테이지 정렬
        List<Integer> sortedStages = Arrays.stream(stages)
                .boxed()
                .sorted(Comparator.reverseOrder())
                .collect(Collectors.toList());

        // 정렬한 스테이지를 순회하며 스테이지별 도전자와 체류자 계산
        for (int i = 0; i < sortedStages.size(); i++) {
            Integer stage = sortedStages.get(i);

            if (stage <= N) {
                List<Integer> failureRate = StageCountMap.get(stage);
                Integer stay = failureRate.get(1);

                // 정렬을 해두었기 때문에 인덱스의 + 1만큼의 사람이 해당 스테이지에 도달 했다고 볼 수 있음
                // 해당 스테이지에 멈춰 있는 사람의 수를 하나 더해준다
                StageCountMap.put(stage, List.of(i + 1, stay + 1));
            } else {
                // 멈춰 있는 스테이지가 마지막 스테이지보다 높을 경우, 마지막 스테이지까지 클리어한 것임
                List<Integer> failureRate = StageCountMap.get(N);
                Integer stay = failureRate.get(1);

                StageCountMap.put(N, List.of(i + 1, stay));
            }
        }

        // map의 rate 계산, 도달한 사람이 0일 경우 실패율도 0
        Map<Integer, Double> StageFailureMap = StageCountMap.entrySet().stream()
                .collect(Collectors.toMap(
                        Map.Entry::getKey,
                        entry -> {
                            List<Integer> count = entry.getValue();

                            int player = count.get(0);
                            int stay = count.get(1);

                            if (player == 0) {
                                return 0.0;
                            }

                            return (double) stay / player;
                        }
                ));

        // 실패율 높은 스테이지부터 정렬
        List<Integer> answer = StageFailureMap.entrySet()
                .stream()
                .sorted(Map.Entry.<Integer, Double>comparingByValue().reversed())
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());

        return answer.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }
}