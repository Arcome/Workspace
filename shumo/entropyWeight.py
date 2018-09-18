# -*- coding:utf-8 -*-
import xlrd
import math

def open_excel(file = "events.xlsx"):
    try:
        data = xlrd.open_workbook(file)
        table = data.sheets()[0]
        return table
    except Exception as e:
        print (str(e))

def getWeights(table):
    ncols = table.ncols
    entropys = []
    for j in range(ncols):
        if j==0:                   #忽略第一行表头
            continue

        col = table.col_values(j)  #取出第j列并作预处理
        del col[0]
        while "" in col:
            col.remove("")   

        s = set([1,6,7,8,9,10,11,12]) #只包含0或1的列
        col_normalize = []
        if(j in s):
            col_normalize = col
        else:
            minCol = min(col)
            maxCol = max(col)
            if(maxCol == minCol):
                col_normalize = col/col[0]
            else:
                for v in col:
                    vn = (v - minCol)/(maxCol - minCol)
                    col_normalize.append(vn)
        entropy = 0
        sumvn = sum(col_normalize)
        for vn in col_normalize:
            p = vn/sumvn
            if p == 0:
                entropy = 0
            else:
                entropy += p*math.log(p)
        entropy = entropy*(-1)/math.log(len(col_normalize))
        entropys.append(entropy)

    weights = []
    lenEntropys = len(entropys)
    sumEntropys = sum(entropys)
    for entropy in entropys:
        w = (1-entropy)/(lenEntropys - sumEntropys)
        weights.append(w)
    return weights

def main():
    table = open_excel()
    weights = getWeights(table)
    with open("weights.txt",'w') as weightsFile:
        weightsNames = table.row_values(0)
        del weightsNames[0]
        for i in range(len(weightsNames)):
            weightsFile.write(str(weightsNames[i])+": "+str(weights[i])+'\n')

if __name__ == "__main__":
    main()