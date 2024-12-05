## While converting the infix to postfix expression we need to consider certain conditions.
1. - Whenever we encounter any operand we push it to the output expression.
2. - If opertors are encountered then we need to consider some conditions such as:
3. - If **(** is found or if the  precedence of incoming operator is more than the top of stack or stack is empty, we push it to the stack directly,
4. else pop the operators till the stack is empty and push the upcoming operator to the stack.
5. - If the scanned character is a ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis.
   - Once the scanning is over, Pop the stack and add the operators in the postfix expression until it is not empty.
