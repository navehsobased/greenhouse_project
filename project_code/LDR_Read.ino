int LDRread () { //פונקציית קריאה מחיישן LDR
  LDRval = analogRead(LDRpin); 
  return (LDRval);
}