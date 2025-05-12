class QueueWithTwoStacks:
    def __init__(self):
        self.stack_in = []
        self.stack_out = []

    def enqueue(self, value):
        self.stack_in.append(value)

    def dequeue(self):
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        if self.stack_out:
            self.stack_out.pop()

    def peek(self):
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        if self.stack_out:
            print(self.stack_out[-1])

# Proses input
q = int(input())
queue = QueueWithTwoStacks()

for _ in range(q):
    command = input().split()
    if command[0] == '1':
        queue.enqueue(int(command[1]))
    elif command[0] == '2':
        queue.dequeue()
    elif command[0] == '3':
        queue.peek()
