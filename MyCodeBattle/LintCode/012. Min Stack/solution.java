/*
 * 在要更新最小值的时候填上当前的最小值。
 */
public class MinStack {
    Stack<Integer> stack = new Stack();
    int minValue = Integer.MAX_VALUE;
    
    public MinStack() {
        // do initialize if necessary
    }

    public void push(int number) {
        if (number <= minValue) {
            stack.push(minValue);
            minValue = number;
        }
        stack.push(number);
    }

    public int pop() {
        int ret = 0;

        if (stack.peek() == minValue) {
            ret = stack.pop();
            minValue = stack.pop();
        }
        else {
            ret = stack.pop();
        }
        return ret;
    }

    public int min() {
        return minValue;
    }
}

