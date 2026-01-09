def pour(from_jug, to_jug): # jug has two attributes capacity and filled_amount.
    if from_jug.filled_amount > (to_jug.capacity - to_jug.filled_amount):
        from_jug.filled_amount -= (to_jug.capacity - to_jug.filled_amount)
        to_jug.filled_amount = to_jug.capacity
    else:
        to_jug.filled_amount += from_jug.filled_amount
        from_jug.filled_amount = 0

class Jug:       #The pour function transfers water from one jug to another.
    def __init__(self, capacity):
        self.capacity = capacity
        self.filled_amount = 0

def main():
    # Define two jugs with capacities 4 and 3
    jug1 = Jug(4)
    jug2 = Jug(3)

    # Fill up jug1
    jug1.filled_amount = 4

    # Pour the contents of jug1 into jug2
    pour(jug1, jug2)
    print("Jug 1:", jug1.filled_amount, "Jug 2:", jug2.filled_amount)

    # Empty jug2
    jug2.filled_amount = 0

    # Pour the contents of jug1 into jug2
    pour(jug1, jug2)
    print("Jug 1:", jug1.filled_amount, "Jug 2:", jug2.filled_amount)

# The main function creates two jugs and performs two pouring operations.
if __name__ == '__main__':
    main()
