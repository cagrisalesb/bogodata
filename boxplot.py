import pandas as pd
import matplotlib.pyplot as plt

college_major_earnings = pd.read_csv('Week1_Day1/recent-college-grads-earnings.csv')

more_men_earnings = college_major_earnings[college_major_earnings['ShareWomen']<0.5]['Median'].values
more_women_earnings = college_major_earnings[college_major_earnings['ShareWomen']>0.5]['Median'].values

two_box_plots=[more_men_earnings, more_women_earnings]

plt.boxplot(two_box_plots)

plt.plot()
plt.savefig('boxplot.png')
plt.show()
