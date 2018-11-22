import random as r

def PickCartas():
    tipo = r.randrange(0,4)
    seleccionada = r.randrange(0,len(cartas[tipo]))
    inicial = cartas[tipo].pop(seleccionada)
    seleccion.append([tipo, inicial])
    if tipo == 0:
        print ("Su carta es ",inicial," de trebol")
    elif tipo == 1:
        print ("Su carta es ",inicial," de pica")
    elif tipo == 2:
        print ("Su carta es ",inicial," de corazon")
    elif tipo == 3:
        print ("Su carta es ",inicial," de diamante")

def MostrarCartas():
    cont = 1
    for j in range(len(seleccion)):
        if seleccion[j][0] == 0:
            print (cont,". ",seleccion[j][1]," de trebol")
        elif seleccion[j][0] == 1:
            print (cont,". ",seleccion[j][1]," de pica")
        elif seleccion[j][0] == 2:
            print (cont,". ",seleccion[j][1]," de corazon")
        elif seleccion[j][0] == 3:
            print (cont,". ",seleccion[j][1]," de diamante")
        cont+=1
    Comparar(seleccion.pop(int(raw_input("Cual carta desea elegir?: "))-1))


def Comparar(carta):
    cont = 1
    for l in range(len(opciones)):
        print (cont,". ",opciones[l])
        cont+=1
    CalcularProbabilidad(int(raw_input("Por cual tipo desea comparar?: ")), carta)

def CalcularProbabilidad(n, carta):
    aux = 0
    print ("La probabilidad de que obtenga otra carta con esa caracteristica es: ",)
    if n == 1:
        if carta[0] == 0 or carta[0] == 1:
            print ("{0:.2f}".format(((len(trebol)+len(pica))/float(cantidad))*100),)
        elif carta[0] == 2 or carta[0] == 3:
            print ("{0:.2f}".format(((len(corazon)+len(diamante))/float(cantidad))*100),)
    elif n == 2:
        if carta[0] == 0:
            print ("{0:.2f}".format((len(trebol)/float(cantidad))*100),)
        elif carta[0] == 1:
            print ("{0:.2f}".format((len(pica)/float(cantidad))*100),)
        elif carta[0] == 2:
            print ("{0:.2f}".format((len(corazon)/float(cantidad))*100),)
        elif carta[0] == 3:
            print ("{0:.2f}".format((len(diamante)/float(cantidad))*100),)
    elif n == 3:
        if carta[1] in trebol:
            aux +=1
        if carta[1] in pica:
            aux +=1
        if carta[1] in corazon:
            aux += 1
        if carta[1] in diamante:
            aux += 1
        print ("{0:.2f}".format((aux/float(cantidad))*100),)
    print ("%")
    print ("")

    
trebol = ["A", 2,3,4,5,6,7,8,9,10,"J","Q","K"]
pica = ["A", 2,3,4,5,6,7,8,9,10,"J","Q","K"]
corazon = ["A", 2,3,4,5,6,7,8,9,10,"J","Q","K"]
diamante = ["A", 2,3,4,5,6,7,8,9,10,"J","Q","K"]
seleccion = []
opciones = ["Color", "Manjar", "Pareja"]
cartas = [trebol, pica, corazon, diamante]

resp = raw_input("¿Desea jugar? Y/N: " )
if resp.upper() == "Y":
    print ("")
    print ("-------------------BIENVENIDO-------------------")
    print ("")
    print ("Se le entregara su carta inicial a continuacion:")
    PickCartas()
    respuesta = raw_input("¿Desea otra carta? Y/N: ")
    if respuesta.upper() == "Y":
        for i in range(int(raw_input("¿Cuantas cartas desea de mas?: "))):
            PickCartas()
        print ("")
        print ("---------------------------------------------------------------------")
        print ("")
    cantidad = 52-len(seleccion)
        
    for j in range(len(seleccion)):
        MostrarCartas()
print ("-------------------FIN-------------------")



    
    
