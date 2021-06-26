#!/usr/bin/env Rscript

print(R.Version())

data<-read.csv("SCPRC-EST2018-18+POP-RES.csv",header=TRUE,sep=",")

population<-data['POPESTIMATE2018']
print('Population')
print(summary(population[-1:-1,]))

pcnt_18plus<-data['PCNT_POPEST18PLUS']
print('Percentage 18+')
print(summary(pcnt_18plus[-1:-1,]))

