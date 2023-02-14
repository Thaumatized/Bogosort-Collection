import random

def Sorted(arr):
	for i in range(len(arr)-1):
		if arr[i] > arr[i+1]:
			return False
	return True
	
def Shuffle(arr):
	for i in range(len(arr)):
		otherindex = random.randint(0, len(arr)-1)		
		holder = arr[otherindex]
		arr[otherindex] = arr[i]
		arr[i] = holder

def Bogosort(arr):
	while not Sorted(arr):
		Shuffle(arr)
		
def RandArray(length = 10, maxvalue=255):
	arr = []
	for i in range(length):
		arr.append(random.randint(0, maxvalue))
	return arr
	
if __name__ == '__main__':
	length = "a"
	while not length.isnumeric():
		print("Please input your desired array length: ")
		length = input()
	maxvalue = "a"
	while not maxvalue.isnumeric():
		print("Please input your desired max number: ")
		maxvalue = input()
	length = int(length)
	maxvalue = int(maxvalue)
	arr = RandArray(length, maxvalue)
	
	print("Start:")
	for number in arr:
		print(str(number) + ", ", end="")
	print()
	Bogosort(arr)
	print("End:")
	for number in arr:
		print(str(number) + ", ", end="")
