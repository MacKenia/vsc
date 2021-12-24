
setTimeout(()=>{
  location.href="./tree.html";
},16*1000);

$('text').each(function () {
  const el = $(this);
  const text = el.html().split('');
  el.html(`<tspan>${text.join('</tspan><tspan>')}</tspan>`);
});