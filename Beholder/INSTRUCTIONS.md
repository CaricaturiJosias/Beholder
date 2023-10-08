# Compilação de arquivo IDL
tao_idl -Gstl Beholder.idl

#Gerando arquivos Avro
avrogencpp -i AnalogData.json -o AnalogData.hh -n c
avrogencpp -i DigitalData.json -o DigitalData.hh -n c