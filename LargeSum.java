import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class LargeSum {
    private static boolean readNum(BufferedReader br, StringBuilder num) throws IOException {
        int c;
        while ((c = br.read()) != -1) {
            if (c >= '0' && c <= '9') {
                num.append((char)c);
            } else if (c == '\n'){
                return true;
            }
        }
        // If a final number is read without a \n, return true
        return !num.isEmpty();
    }

    private static void addNum(StringBuilder num1, StringBuilder num2) {
        int length1 = num1.length();
        int length2 = num2.length();
        int maxLength = Math.max(length1, length2);
        int carry = 0;

        for (int i = 0; i < maxLength; i++) {
            int digit1 = i < length1 ? num1.charAt(i) - '0' : 0;
            int digit2 = i < length2 ? num2.charAt(i) - '0' : 0;
            int sum = digit1 + digit2 + carry;
            char resultDigit = (char)('0' + sum % 10);
            carry = sum / 10;

            if (i < length1) {
                num1.setCharAt(i, resultDigit);
            } else {
                num1.append(resultDigit);
            }
        }
        if (carry > 0) {
            num1.append((char)('0' + carry));
        }

        while (num1.length() > 1 && num1.charAt(num1.length() - 1) == '0') {
            num1.deleteCharAt(num1.length() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        StringBuilder total = new StringBuilder("0");

        try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            while (true) {
                StringBuilder num = new StringBuilder();
                if (!readNum(br, num)) {
                    break;
                }
                num.reverse(); // We need the LSB at index 0
                addNum(total, num);
            }
        }

        String fullSum = new StringBuilder(total).reverse().toString();
        int endIndex = Math.min(10, fullSum.length());
        String firstTenDigits = fullSum.substring(0, endIndex);
        System.out.println("Full sum: " + fullSum);
        System.out.println("First 10 digits: " + firstTenDigits);
    }
}
