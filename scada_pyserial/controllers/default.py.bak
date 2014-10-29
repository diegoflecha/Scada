import math
import datetime
import serial
import time
import os.path
global puerto_Serie

for i in range(11):
    puerto ="/dev/ttyACM" + str(i)
    if os.path.exists(puerto):
        break
try:
    puerto_Serie=serial.Serial(puerto, 9600)
 
except Exception,e:
    print e
    

global dato_caudal
global dato_alarma
global dato_nivel
global lista
nivel_recibido= ''



buffer=""
dato_alarma=""
dato_nivel=""
dato_caudal=""
lista=[]
puerto_Serie.close()
puerto_Serie.open()
if puerto_Serie.inWaiting()>0:
    
    buffer = buffer + puerto_Serie.read(puerto_Serie.inWaiting())
    
    if '\n' in buffer:
           
           nivel_recibido, buffer = buffer.split('\n')[-2:]
           dato_alarma=nivel_recibido[0]
           dato_nivel= nivel_recibido[1]
           dato_caudal= nivel_recibido[2]  
           lista= [ dato_alarma,dato_nivel,dato_caudal]
           time.sleep(0.01)
       
def index():
    """
    example action using the internationalization operator T and flash
    rendered by views/default/index.html or views/generic.html

    if you need a simple wiki simply replace the two lines below with:
    return auth.wiki()
    """
    response.flash = T("Welcome to web2py!")
    return dict(message=T('Hello World'))



def pide_hora():
 
    hora=datetime.datetime.now().strftime("%H:%M:%S")
    fecha=datetime.datetime.now().strftime("%d-%m-%Y")
    return dict(hora=hora,fecha=fecha)

def pide_datos():
    
    print lista

    return dict(dato_alarma=dato_alarma,dato_nivel=dato_nivel,dato_caudal=dato_caudal)

def recibe_datos():
    
      
    operando1=int(request.vars.operando1)
    if operando1==1:
        operando1="1"
    if operando1==0:
        operando1="0"
    puerto_Serie.write(operando1)
    print operando1 
   

def user():
    """
    exposes:
    http://..../[app]/default/user/login
    http://..../[app]/default/user/logout
    http://..../[app]/default/user/register
    http://..../[app]/default/user/profile
    http://..../[app]/default/user/retrieve_password
    http://..../[app]/default/user/change_password
    http://..../[app]/default/user/manage_users (requires membership in
    use @auth.requires_login()
    @auth.requires_membership('group name')
    @auth.requires_permission('read','table name',record_id)
    to decorate functions that need access control
    """
    return dict(form=auth())

@cache.action()
def download():
    """
    allows downloading of uploaded files
    http://..../[app]/default/download/[filename]
    """
    return response.download(request, db)

def call():
    """
    exposes services. for example:
    http://..../[app]/default/call/jsonrpc
    decorate with @services.jsonrpc the functions to expose
    supports xml, json, xmlrpc, jsonrpc, amfrpc, rss, csv
    """
    return service()


@auth.requires_signature()
def data():
    """
    http://..../[app]/default/data/tables
    http://..../[app]/default/data/create/[table]
    http://..../[app]/default/data/read/[table]/[id]
    http://..../[app]/default/data/update/[table]/[id]
    http://..../[app]/default/data/delete/[table]/[id]
    http://..../[app]/default/data/select/[table]
    http://..../[app]/default/data/search/[table]
    but URLs must be signed, i.e. linked with
        A('table',_href=URL('data/tables',user_signature=True))
      or with the signed load operator
     LOAD('default','data.load',args='tables',ajax=True,user_signature=True)
    """
    return dict(form=crud())
