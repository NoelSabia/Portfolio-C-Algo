def get_integer_input(promt):
	while True:
		try:
			value = int(input(promt))
			return value
		except ValueError:
			print("PLease enter a valid integer.")

def get_yes_no_input(prompt):
	while True:
		response = input(prompt).strip().lower()
		if response in ('yes', 'y'):
			return True
		elif response in ('no', 'n'):
			return False
		else:
			print("Please enter 'yes' or 'no'.")

def create_num_file(nums):
	with open('nums-txt', 'w') as file:
		for num in nums:
			file.write(str(num) + '\n')

def main():
	num_count = get_integer_input("How many numbers do you want to intput? ")
	allow_rep_num = get_yes_no_input("Allow repeating numbers? (yes/no) ")
	use_own_file = get_yes_no_input("Do you want to use your own numfile? (yes/no) ")

	if use_own_file:
		print("Please input the numbers in nums.txt file.")
		return
	
	nums = []
	print("Enter the numbers one by one:<space><number><comma>")
	for i in range(num_count):
		num = get_integer_input(f"Enter number {i + 1}: ")
		if not allow_rep_num and num in nums:
			print("Error: Repeating numbers are not allowed.")
			return
		nums.append(num)
	
	create_num_file(nums)
	print("nums.txt has been created with the numbers.")


if __name__ == "__main__":
	main()