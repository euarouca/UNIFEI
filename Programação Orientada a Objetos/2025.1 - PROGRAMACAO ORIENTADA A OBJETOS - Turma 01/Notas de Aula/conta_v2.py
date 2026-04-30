from abc import ABC, abstractmethod


####### Seu código


if __name__=="__main__":
    contas = []
    cc = ContaCorrente(1111, 'João Silva', 0, 30)
    cc.deposito(1000, 'Crédito salário')
    if cc.saque(-500, 'Pagto energia'):
        print('Saque de R$500,00 na conta {}'.format(cc.nroConta))
    else:
        print('Falha ao realizar saque de R$500,00 na conta {}'.format(cc.nroConta))
    if cc.saque(-700, 'PIX'):
        print('Saque de R$700,00 na conta {}'.format(cc.nroConta))
    else:
        print('Falha ao realizar saque de R$700,00 na conta {}'.format(cc.nroConta))
    contas.append(cc)

    print()

    cl = ContaLimite(2222, 'Ana Souza', 0, 1000)
    cl.deposito(1500, 'Crédito salário')
    if cl.saque(-1200, 'Pagto boleto'):
        print('Saque de R$1200,00 na conta {}'.format(cl.nroConta))
    else:
        print('Falha ao realizar saque de R$1200,00 na conta {}'.format(cl.nroConta))
    if cl.saque(-500, 'PIX'):
        print('Saque de R$500,00 na conta {}'.format(cl.nroConta))
    else:
        print('Falha ao realizar saque de R$500,00 na conta {}'.format(cl.nroConta))
    contas.append(cl)

    print()

    cp = ContaPoupanca(3333, 'João Silva', 0, 10)
    cp.deposito(1200, 'Econominas')
    if cp.saque(-400, 'Resgate 1'):
        print('Saque de R$400,00 na conta {}'.format(cp.nroConta))
    else:
        print('Falha ao realizar saque de R$500,00 na conta {}'.format(cp.nroConta))
    if cp.saque(-300, 'Resgate 2'):
        print('Saque de R$300,00 na conta {}'.format(cp.nroConta))
    else:
        print('Falha ao realizar saque de R$700,00 na conta {}'.format(cp.nroConta))
    contas.append(cp)

    print()

    for conta in contas:
        conta.impExtrato()
        print()