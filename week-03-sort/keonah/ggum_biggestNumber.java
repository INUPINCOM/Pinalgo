import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Comparator;

class Solution {
    public String solution(int[] numbers) {

        // 숫자들을 이어 붙여 큰 수를 만들 때 가장 높은 자리 숫자가 커질수록 결과물이 커짐
        // 따라서 숫자를 문자열로 바꾼 후 정렬
        // 테스트 케이스를 보면 30보다 3이 더 앞으로 와야 하기에 정렬 시 앞뒤 숫자를 이어 붙여본 후 비교
        String answer = Arrays.stream(numbers)
                .mapToObj(String::valueOf)
                .sorted((a, b) -> (b + a).compareTo(a + b))
                .collect(Collectors.joining());

        // 반례: 배열에 0 여러 개가 주어질 경우, 0000이 아닌 0이 되어야 함 (질문하기 참고)
        if (answer.startsWith("0")) {
            answer = "0";
        }

        return answer;
    }
}