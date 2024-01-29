import random

def generate_and_save_random_numbers(n, file_path):
    random_numbers = [random.randint(1, 10000) for _ in range(n)]

    with open(file_path, 'w') as file:
    	file.write(n + '\n')
        for number in random_numbers:
            file.write(str(number) + ' ')

file_path = 'LAB2/input.txt'

generate_and_save_random_numbers(10000, file_path)

