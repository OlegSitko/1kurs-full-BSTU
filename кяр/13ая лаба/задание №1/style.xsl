<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
   xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
   <html>
   <head>
      <style>table{border:1px solid black;border-collapse: collapse}
         td{border:1px solid black;padding:3px}
      </style>
   </head>
   <body>
   <h2>car models</h2>
   <table >
  
  
      <tr>
         <xsl:for-each select="root/heading/*">
         <td > <xsl:value-of select="."/></td>
         </xsl:for-each>
      
      </tr>
       
      <xsl:for-each select="root/car">
      <xsl:sort select="price" order="ascending" data-type="number"/>
      <tr>
         
      <xsl:for-each select="*">
      <td> <xsl:value-of select="."/></td>
      </xsl:for-each>
      </tr>
       
      </xsl:for-each>
   </table>
   </body>
   </html>
</xsl:template>

</xsl:stylesheet> 