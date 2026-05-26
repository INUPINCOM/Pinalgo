class Solution {
    public int[] solution(String[] info, String[] query) {

        int[] answer = new int[query.length];

        for (int i = 0; i < query.length; i++) {
            int count = 0;
            String[] q = query[i].split(" ");

            for (int j = 0; j < q.length; j++) {
                if (q[j].equals("-")) {
                    q[j] = "";
                }
            }

            int k = 0;
            for (String temp : info) {
                String[] x = temp.split(" ");
                if(x[0].contains(q[0]) && x[1].contains(q[2]) && x[2].contains(q[4]) && x[3].contains(q[6]) && Integer.valueOf(x[4]) >= Integer.valueOf(q[7])) {
                    count++;
                }
            }
            answer[i] = count;
        }


        return answer;
    }
}
