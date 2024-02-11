<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" 
   xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<!-- данный документ является таблицей  стилей  XSLT  с  атрибутами  номера  версии  и  пространства имен XSLT. -->

<xsl:template match="/">
 <!-- указывает,  как  должны  преобразовываться части документа XML. Значение «/» атрибут match используется, чтобы определить шаблон для всего XML документа целиком. -->
   <html>
   <head>
      <style>table{border:1px solid black;border-collapse: collapse}
          td{border:1px solid black;padding:3px}
      </style>
   </head>
   <body>
   <h2>Аттестация студентов фит 2 группа</h2>
   <table >
  
  
   <tr>
      <xsl:for-each select="root/heading/*">
      <td> <xsl:value-of select="."/></td>
       <!-- используется  для  извлечения  значения  ото- -->
<!-- бранного XML элемента и добавления его в выходной поток пре- -->
<!-- образовываемого документа.  -->
      </xsl:for-each>
   
   </tr>
    
   <xsl:for-each select="root/student">
   <!-- может  использоваться  для  выбора  каждого  -->
<!-- XML элемента заданного узлового набора  -->
   <tr>
   
   <xsl:for-each select="*">
   <xsl:choose> 
   <!-- <xsl:choose>  используется  вместе  с  элементами  -->
<!-- <xsl:when> и <xsl:otherwise>, чтобы определить проверку на вы- -->
<!-- полнение  условия. -->
   <xsl:when test=".&lt;'4'">
      <td style="background:red;color: white"> <xsl:value-of select="."/></td>

   </xsl:when >
   <xsl:when test=".&gt;'8'">
      <td style="background:green;color: white"><xsl:value-of select="."/></td>

   </xsl:when >
   <xsl:otherwise>
      <td ><xsl:value-of select="."/></td>
   </xsl:otherwise>

   </xsl:choose>
   </xsl:for-each>
   </tr>
    
   </xsl:for-each>
   </table>
   </body>
   </html>
</xsl:template>

</xsl:stylesheet> 