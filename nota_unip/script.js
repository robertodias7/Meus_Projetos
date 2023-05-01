function Calcular(){
    let notaProva = prompt('Digite a Nota da Prova')
    let notaPim = prompt('Digite a Nota do PIM')
    let notaAva = prompt('Digite a Nota do AVA')
    let res = document.getElementById('res')
    let media = Number((7 * notaProva) + (2 * notaPim) + 1 * notaAva) / 10
    let mediaLimite = 6

    res.innerHTML = `Nota da Prova: ${notaProva}<br>`
    res.innerHTML += `Nota do PIM: ${notaPim}<br>`
    res.innerHTML += `Nota do AVA: ${notaAva} <br>`
    

    if(media >= mediaLimite){
        res.innerHTML += `Sua Nota é ${media.toFixed(1).replace('.', ',')} e você foi APROVADO!`
    }else{
        res.innerHTML += `Sua Nota é ${media.toFixed(1).replace('.', ',')} e você não está APROVADO!`
    }
}