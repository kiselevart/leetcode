public class DailyTemperature {
    public int[] dailyTemperature(int[] temperatures) {
        int[] answer = new int[temperatures.length];

        for (int i=0; i<temperatures.length; i++) {
            int currentTemp = temperatures[i];
            int count = 0;
            if (currentTemp == 100) {continue;}

            for (int j=i; j<temperatures.length; j++) {
                if (temperatures[j] > currentTemp) {
                    answer[i] = count;
                    break;
                }
                else {
                    count++;
                }
            }
        }
        
        return answer;
    }
}
