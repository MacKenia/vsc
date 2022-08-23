from docx import Document
from docxcompose.composer import Composer
import os, re

docxFile = re.compile(".*\.docx$")

new_docx = Document()
composer = Composer(new_docx)

for _, _, files in os.walk("."):
    for file in files:
        if docxFile.match(file):
            print("正在合并: ", file)
            openDoc = Document(file)
            openDoc.add_section()
            composer.append(openDoc)
    
composer.save("OutPut.docx")
print("导出到 OutPut.docx")
