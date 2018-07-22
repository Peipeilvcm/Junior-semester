
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class EditStrategyUI extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JTextField strategyNameField;
	private JTextField strategyValueField;
	private JComboBox<String> bookTypeCombox;
	private JComboBox<String> strategyTypeCombox;
	
	public EditStrategyUI(StrategiesUI parent, int strategyNum){
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				parent.setEnabled(true);
			}
		});
		
		initializeUI(strategyNum);
		
		
	}
	
	private void initializeUI(int strategyNum){
		
		this.setTitle("策略编辑");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.setBounds(100, 100, 360, 270);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		this.getContentPane().setLayout(null);
		
		IPricingStrategy strategy = Controller.getInstance().getStrategy(strategyNum);
		
		JLabel label1 = new JLabel("策略名称");
		label1.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label1.setBounds(30, 35, 65, 25);
		this.getContentPane().add(label1);
		
		strategyNameField = new JTextField();
		strategyNameField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		strategyNameField.setBounds(100, 35, 215, 25);
		strategyNameField.setColumns(12);
		strategyNameField.setText(strategy.getStrategyName());
		this.getContentPane().add(strategyNameField);
		
		JLabel label2 = new JLabel("策略类型");
		label2.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label2.setBounds(30, 70, 60, 25);
		this.getContentPane().add(label2);
		
		strategyTypeCombox = new JComboBox<String>();
		strategyTypeCombox.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		strategyTypeCombox.setBounds(100, 70, 215, 25);
		strategyTypeCombox.setModel(new DefaultComboBoxModel<String>(new String[] {
				"百分比优惠策略", "绝对值优惠策略", "用户最优策略"
		}));
		strategyTypeCombox.setSelectedIndex(strategy.getStrategyType()-1);
		strategyTypeCombox.setEnabled(false);//不可编辑
		this.getContentPane().add(strategyTypeCombox);
		
		JLabel label3 = new JLabel("适用类型");
		label3.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label3.setBounds(30, 105, 60, 25);
		this.getContentPane().add(label3);
		
		bookTypeCombox = new JComboBox<String>();
		bookTypeCombox.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		bookTypeCombox.setBounds(100, 105, 215, 25);
		bookTypeCombox.setModel(new DefaultComboBoxModel<String>(new String[] {
				"暂不应用", "非教材类计算机图书", "教材类图书", "连环画类图书", "养生类图书", "其他"
		}));
		bookTypeCombox.setSelectedIndex(strategy.getBookType());
		this.getContentPane().add(bookTypeCombox);
		
		JLabel label4 = new JLabel("策略值");
		label4.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label4.setBounds(30, 140, 60, 25);
		this.getContentPane().add(label4);
		
		/*
		JLabel label5 = new JLabel("元");
		label5.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		label5.setBounds(290, 140, 18, 25);
		this.getContentPane().add(label5);*/
		
		strategyValueField = new JTextField();
		strategyValueField.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		strategyValueField.setBounds(100, 140, 185, 25);
		strategyValueField.setColumns(12);
		strategyValueField.setText(strategy.getStrategyValue());
		this.getContentPane().add(strategyValueField);
		
		//返回键
	    JButton returnButton = new JButton("返回策略管理");
		returnButton.addActionListener((e) -> {
			//关闭窗口
			dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));		
		});
		returnButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
		returnButton.setBounds(195, 180, 120, 30);
		this.getContentPane().add(returnButton);
		
		//确认添加
	    JButton confirmAddButton = new JButton("确认修改策略");
	    confirmAddButton.addActionListener((e) -> {
			//确认添加
			confirmEditStrategy(strategyNum, strategy.getBookType());
		});
	    confirmAddButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 14));
	    confirmAddButton.setBounds(35, 180, 120, 30);
		this.getContentPane().add(confirmAddButton);
		
	}
	
	private void confirmEditStrategy(int strategyNum, int bType){
		String name = strategyNameField.getText();
		int strategyType = strategyTypeCombox.getSelectedIndex();
		int bookType = bookTypeCombox.getSelectedIndex();
		String value = strategyValueField.getText();
		
		if(name.isEmpty() || value.isEmpty()){
			Controller.getInstance().messageBox("信息填写不完整！请检查", "WARNING");
			return;
		}
		
		if(bookType != bType){
			if(StrategyCatalog.getInstance().isOccupied(bookType)){
				Controller.getInstance().messageBox("此类图书已经有一种优惠方式,请先移除再添加", "WARNING");
				return;
			}
		}
		
		IPricingStrategy newStrategy = null;
		if(strategyType == 0){
			int actuallValue = 0;
			try{
				actuallValue = Integer.parseInt(value);
				if(actuallValue <= 0 || actuallValue > 100){
					Controller.getInstance().messageBox("输入百分比错误，应为1~100整数", "WARNING");
					return;
				}
			}
			catch(Exception ex){
				Controller.getInstance().messageBox("输入百分比错误，应为1~100整数", "ERROR");
				return;
			}
			
			newStrategy = new PrecentageStrategy(strategyNum, name, actuallValue);
		}
		else if(strategyType == 1){
			double actuallValue = 0.0;
			try{
				actuallValue = Float.parseFloat(value);
				if(actuallValue <= 0){
					Controller.getInstance().messageBox("输入优惠值错误>0的浮点数", "WARNING");
					return;
				}
			}
			catch(Exception ex){
				Controller.getInstance().messageBox("输入优惠值错误>0的浮点数", "ERROR");
				return;
			}
			
			newStrategy = new FlatRateStrategy(strategyNum ,name, actuallValue);
		}
		else{
			newStrategy = new CompositeBestForCustomer(strategyNum, name);
			if(!newStrategy.setStrategyValue(value)){
				Controller.getInstance().messageBox("策略值输入错误", "ERROR");
				return;
			}
			
		}
		newStrategy.setBookType(bookType);
		
		Controller.getInstance().editStrategy(strategyNum, newStrategy);
		Controller.getInstance().updateStrategy();
		//Controller.getInstance().updateSale();
		
		Controller.getInstance().messageBox("修改策略成功", "SUCCESS");
	}
	
}
