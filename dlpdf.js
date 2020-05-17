let out = document.createElement("script");
 
out.onload = function () {
 
    let out = new jsPDF();
    let elements = document.getElementsByTagName("img");
    for (let i in elements) {
        let img = elements[i];
        console.log("add img ", img);
        if (!/^blob:/.test(img.src)) {
            console.log("invalid src");
            continue;
        }
        let can = document.createElement('canvas');
        let con = can.getContext("2d");
        can.width = img.width;
        can.height = img.height;
        con.drawImage(img, 0, 0);
        let imgData = can.toDataURL("image/jpeg", 1.0);
        out.addImage(imgData, 'JPEG', 0, 0);
        out.addPage();
    }
 
    out.save("out.pdf");
};
 
out.src = 'https://cdnjs.cloudflare.com/ajax/libs/jspdf/1.5.3/jspdf.debug.js';
document.body.appendChild(out);