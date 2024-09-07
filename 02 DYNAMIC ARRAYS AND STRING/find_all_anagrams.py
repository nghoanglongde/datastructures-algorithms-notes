#!/bin/python3

import math
import os
import random
import re
import sys
import pandas as pd

#
# Complete the 'schoolCount' function below.
#
# The function is expected to return a pandas dataframe.
#

def schoolCount(df):
    # Write your code here
    condition_substr = df["subjects"].str.split().str.len()
    filtered_df = df[condition_substr > 3]
    
    filtered_df['state_code'] = filtered_df['state_code'].apply(lambda x: re.sub(r'[^a-zA-Z0-9]', '', x))
    
    def count_subjects(subject_list):
        subject_counts = {}
        for subject in subject_list:
            if subject in subject_counts:
                subject_counts[subject] += 1
            else:
                subject_counts[subject] = 1
        return pd.Series(subject_counts)

    # Group by state_code and calculate subject counts for each group
    subject_counts_per_state = filtered_df.groupby('state_code')['subjects'].apply(lambda x: count_subjects(x.split())).fillna(0).astype(int)
    
    return subject_counts_per_state

    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    df = pd.read_csv('/dev/stdin')
    
    result = schoolCount(df)
    fptr.write(result.to_csv(index=False))

    fptr.close()
