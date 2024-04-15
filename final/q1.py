for n in range(100):
	suma_cubs = 0
	for i in range(8):
		suma_cubs += (n + i)**3
	if suma_cubs % 2024 == 0:
		print(suma_cubs)