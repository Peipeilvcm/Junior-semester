import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Vector;

import javax.swing.*;
import javax.swing.table.*;


public class StrategiesUI extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JTable table;
	private Observer observer;
	
	public StrategiesUI(MainUI parent){
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				parent.setEnabled(true);
				StrategyCatalog.getInstance().removeObserver(observer);
				//parent.closeShopCartUI();
			}
		});
		
		initializeUI();
		observer = new StrategyUIObserver();
		StrategyCatalog.getInstance().registerObserver(observer);
		observer.update();

	}
	
	class ModelTable extends DefaultTableModel{
		private static final long serialVersionUID = 1L;
		private Vector< ArrayList<String> > tableData;
		private Vector<String> tableTitle;
		
		public ModelTable(){
			tableData = new Vector< ArrayList<String> >();
            tableTitle = new Vector<String>();
            setDataVector(tableData, tableTitle);
            tableTitle.add("策略编号");
            tableTitle.add("策略名称");
            tableTitle.add("Values");
            tableTitle.add("策略类型");
            tableTitle.add("应用图书类别");
		}
		
		private void addStrategy(IPricingStrategy strategy){
			ArrayList<String> line = new ArrayList<String>();
			line.add(""+strategy.getStrategyNum());
			line.add(strategy.getStrategyName());
			line.add(strategy.getStrategyValue());
			line.add(strategy.getStrategyTypeStr());
			line.add(Controller.getInstance().bookTypeToStr(strategy.getBookType()));
			
			tableData.add(line);
		}
		
		public void updateUI(){
			tableData.clear();
			for(IPricingStrategy strategy : StrategyCatalog.getInstance().getStrategies()){
				if(strategy.getStrategyNum()!=0){
					addStrategy(strategy);
				}
			}
			table.repaint();
			table.updateUI();
		}
		
		public String getValueAt(int rowIndex, int colIndex){
			ArrayList<String> list = this.tableData.get(rowIndex);
			return list.get(colIndex);
		}
		
		public boolean isCellEditable(int rowIndex, int colIndex){
			return false;
		}
		
	}
	
	class StrategyUIObserver implements Observer{
		public void update(){
			ModelTable model = (ModelTable) table.getModel();
			model.updateUI();
		}
	}
	
	private void initializeUI(){
		this.setTitle("策略管理");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.setBounds(100, 100, 570, 280);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		//策略目录表格初始化
		table = new JTable();
		table.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		
		table.setModel(new ModelTable());
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		DefaultTableCellRenderer tcr = new DefaultTableCellRenderer();
		tcr.setHorizontalAlignment(SwingConstants.CENTER);
		table.setDefaultRenderer(Object.class, tcr);
		table.getTableHeader().setReorderingAllowed(false);
		table.getTableHeader().setResizingAllowed(false);
	    table.getColumnModel().getColumn(0).setPreferredWidth(10);
	    table.getColumnModel().getColumn(1).setPreferredWidth(80);
	    table.getColumnModel().getColumn(2).setPreferredWidth(40);
	    table.getColumnModel().getColumn(3).setPreferredWidth(90);
	    table.getColumnModel().getColumn(4).setPreferredWidth(90);
	    
	  //显示表格
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(13, 19 , 540, 180);
		this.getContentPane().add(scrollPane);
		scrollPane.setViewportView(table);
	    
	    this.getContentPane().setLayout(null);
	    
 //下面是功能按钮：
	    
	    //返回键
	    JButton returnButton = new JButton("返回主界面");
		returnButton.addActionListener((e) -> {
			//返回主界面
			dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));		
		});
		returnButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		returnButton.setBounds(432, 210, 120, 30);
		this.getContentPane().add(returnButton);
		
		//删除选中策略
		JButton delButton = new JButton("删除所选策略");
		delButton.addActionListener((e) -> {
			//删除动作
			delStrategy();
		});
		delButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		delButton.setBounds(292, 210, 120, 30);
		this.getContentPane().add(delButton);
		
		//编辑选中策略
		JButton editButton = new JButton("编辑选中策略");
		editButton.addActionListener((e) -> {
			//编辑动作
			editStrategy();
		});
		editButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		editButton.setBounds(152, 210, 120, 30);
		this.getContentPane().add(editButton);
		
		//增加策略
		JButton addButton = new JButton("新增策略");
		addButton.addActionListener((e) -> {
			//新增动作
			addStrategy();
		});
		addButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		addButton.setBounds(12, 210, 120, 30);
		this.getContentPane().add(addButton);
		
	}
	
	private void delStrategy(){
		int selectedRow = table.getSelectedRow();
		if(selectedRow < 0){
			Controller.getInstance().messageBox("未选择要删除的策略", "WARNING");
			return;
		}
		
		int strategyNum = Integer.parseInt((String)table.getValueAt(selectedRow, 0));
		//System.out.println(strategyNum);
		Controller.getInstance().removeStrategy(strategyNum);
		Controller.getInstance().messageBox("删除成功！", "SUCCESS");
		table.clearSelection();
	}
	
	private void editStrategy(){
		int selectedRow = table.getSelectedRow();
		if(selectedRow < 0){
			Controller.getInstance().messageBox("未选择要编辑的图书", "WARNING");
			return;
		}
		
		int strategyNum = Integer.parseInt((String)table.getValueAt(selectedRow, 0));
		EditStrategyUI editStrategyUII = new EditStrategyUI(this, strategyNum);
		editStrategyUII.setVisible(true);
		this.setEnabled(false);
		
	}
	
	private void addStrategy(){
		AddStrategyUI addStrategyUI = new AddStrategyUI(this);
		addStrategyUI.setVisible(true);
		this.setEnabled(false);
	}
}

