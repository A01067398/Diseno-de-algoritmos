romanos = [
    ["","I","II","III","IV","V","VI","VII","VIII","IX"],
    ["","X","XX","XXX","XL","L","LX","LXX","LXX","XC"],
    ["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"],
    ["","M","MM","MMM","MV","V","VM","VMM","VMMM","MX"]
    ]

def evaluar(numero):
    millares = int(numero / 1000)
    centenas = int(numero % 1000 / 100)
    decenas = int(numero % 1000 % 100 / 10)
    unidades = int(numero % 1000 % 100 % 10)
    
    return romanos[3][millares] + romanos[2][centenas] + romanos[1][decenas] + romanos[0][unidades]

if __name__ == '__main__':
    try:
        numero = int(input('Número a evaluar: '))
        
        print('El número en romano es: %s' % (evaluar(numero)))
    except:
        print('El algoritmo no soporta hacer esta conversión')

