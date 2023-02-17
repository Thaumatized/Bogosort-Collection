import random
import sys
import time

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
	length = 10
	maxvalue = 255
	count = 1
	verbose = False
	arr = []
	individualtimes = []
	
	letter = ""
	i = 1
	while i < len(sys.argv):
		'''Waiting for python3.10
		match sys.argv[i]:
			case "-l":
				length = int(sys.argv[i+1])
			case "-m":
				maxvalue = int(sys.argv[i+1])
			case "-c":
				count = int(sys.argv[i+1])
		i+=1
		'''
	
		if sys.argv[i] == "-l":
			length = int(sys.argv[i+1])
			i+=1
		if sys.argv[i] == "-m":
			maxvalue = int(sys.argv[i+1])
			i+=1
		if sys.argv[i] == "-c":
			count = int(sys.argv[i+1])
			i+=1
		if sys.argv[i] == "-v":
			verbose = True
		if sys.argv[i] == "-a":
			while i+1 < len(sys.argv) and sys.argv[i+1].isnumeric():
				arr.append(int(sys.argv[i+1]))
				i+=1
		i+=1
		
	if arr != []:
		starttime = time.time()
		Bogosort(arr)
		totaltime = time.time() - starttime
		for number in arr:
			print(str(number) + ", ", end="")
	else:
		starttime = time.time()
		for i in range(count):
			if verbose:
				individualstarttime = time.time()
			arr = RandArray(length, maxvalue)
			Bogosort(arr)
			if verbose:
				individualtimes.append(time.time() - individualstarttime)
				print("time " + str(i) + ":", float(int(((time.time() - individualstarttime))*1000))/1000)
		totaltime = time.time() - starttime
		if verbose:
			summeduptotaltime = 0
			for time in individualtimes:
				summeduptotaltime += time
				print("time:", float(int(time*1000))/1000)
			print("average time:", float(int((summeduptotaltime/count)*1000))/1000)
			print("summed up time:", float(int(summeduptotaltime*1000))/1000)
		print("total time:", float(int(totaltime*1000))/1000)
