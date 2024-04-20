valids = 0
for i in range(1, 2025):
	suma_cubs = 0
	for j in range(8):
		suma_cubs += (i + j)**3
	if suma_cubs % 2024 == 0:
		valids += 1

total = 2024**2024 * valids // 2024

suma_digits = 0
while total:
	suma_digits += total%10
	total //= 10

print("Suma dels digits: ", suma_digits)