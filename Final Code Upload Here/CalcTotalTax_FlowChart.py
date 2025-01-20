from graphviz import Digraph

# Create a Digraph object
dot = Digraph(comment='Tax Calculation Flowchart')

# Adding nodes for key steps in the code
dot.node('Start', 'Start', shape='ellipse')
dot.node('CalcIncome', 'Calculate Total Income and Reliefs', shape='box')
dot.node('CalcChargeableIncome', 'Compute Chargeable Income', shape='box')
dot.node('CheckIncome', 'Is Chargeable Income < RM 35,000?', shape='diamond')
dot.node('400Rebate', 'Entitled to RM 400 Rebate', shape='box')
dot.node('NoRebate', 'No Income-based Rebate', shape='box')
dot.node('Religion', 'Input Religion (Islam/Other)', shape='box')
dot.node('Zakat', 'Input Zakat (if Islam)', shape='box')
dot.node('Pilgrimage', 'Made Pilgrimage Before? (Yes/No)', shape='diamond')
dot.node('NumPilgrimages', 'Input Number of Pilgrimages', shape='box')
dot.node('Travelled', 'Travelled this year? (Yes/No)', shape='diamond')
dot.node('Destination', 'Input Destination (Asia/Other)', shape='box')
dot.node('Cabin', 'Input Cabin Class (Economy/Other)', shape='box')
dot.node('CalcRebate', 'Calculate Pilgrimage Rebate', shape='box')
dot.node('CalcTax', 'Calculate Tax Based on Income Slabs', shape='box')
dot.node('FinalRebate', 'Compute Total Rebate (Zakat + Pilgrimage)', shape='box')
dot.node('ApplyRebate', 'Apply Rebate to Tax', shape='box')
dot.node('Output', 'Display Final Tax Payable', shape='box')
dot.node('End', 'End', shape='ellipse')

# Adding edges
dot.edge('Start', 'CalcIncome')
dot.edge('CalcIncome', 'CalcChargeableIncome')
dot.edge('CalcChargeableIncome', 'CheckIncome')
dot.edge('CheckIncome', '400Rebate', label='Yes')
dot.edge('CheckIncome', 'NoRebate', label='No')
dot.edge('400Rebate', 'Religion')
dot.edge('NoRebate', 'Religion')
dot.edge('Religion', 'Zakat', label='Islam')
dot.edge('Religion', 'Pilgrimage', label='Other')
dot.edge('Zakat', 'Pilgrimage', label='Proceed')
dot.edge('Pilgrimage', 'NumPilgrimages', label='Yes')
dot.edge('Pilgrimage', 'CalcTax', label='No')
dot.edge('NumPilgrimages', 'Travelled')
dot.edge('Travelled', 'Destination', label='Yes')
dot.edge('Travelled', 'CalcTax', label='No')
dot.edge('Destination', 'Cabin')
dot.edge('Cabin', 'CalcRebate')
dot.edge('CalcRebate', 'FinalRebate')
dot.edge('CalcTax', 'FinalRebate')
dot.edge('FinalRebate', 'ApplyRebate')
dot.edge('ApplyRebate', 'Output')
dot.edge('Output', 'End')

# Render the flowchart to a file and display
file_path = './Tax_Calculation_Flowchart'  # Use a relative path
dot.render(file_path, format='png', cleanup=True)
print(f"Flowchart saved to {file_path}.png")