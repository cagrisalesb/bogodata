import pandas as pd
import matplotlib.pyplot as plt

roman_emperors=pd.read_csv('Week1_Day1/roman-emperor-reigns.csv')
roman_emperors_reign_lengths=roman_emperors['Length_of_Reign'].values

plt.hist(roman_emperors_reign_lengths)

plt.plot()
plt.savefig('histogram.png')
plt.show()
