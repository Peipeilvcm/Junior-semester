
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;

import java.awt.*;
import java.util.ArrayList;
import java.util.Vector;

public class MainUI extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JTable table;			//��ʾͼ��Ŀ¼
	private Observer observer;		
	private ShoppingCartUI shopCartUI;	//���ﳵĿ¼
	private JSpinner spinner;
	private JLabel bookSelected;
	
	public MainUI(){
		initializeUI();
		observer = new MainUIObserver();
		BookCatalog.getInstance().registerObserver(observer);
		//�Ƿ���г�ʼ��
		shopCartUI = null;
		if(JOptionPane.showConfirmDialog(null, "��ѡ���Ƿ����Զ�����ͼ�������",
				"ͼ�����",JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION){
			Controller.getInstance().initInfo();
			openShopCartUI();
			observer.update();
		}
		//BookCatalog.getInstance().update();
	}
	
	class ModelTable extends DefaultTableModel{
		private static final long serialVersionUID = 1L;
		private Vector< ArrayList<String> > tableData;
		private Vector<String> tableTitle;
		
		public ModelTable(){
			tableData = new Vector< ArrayList<String> >();
            tableTitle = new Vector<String>();
            setDataVector(tableData, tableTitle);
            tableTitle.add("����");
            tableTitle.add("ISBN");
            tableTitle.add("����");
            tableTitle.add("�۸�");
		}
		
		public void addBook(BookSpecification book){
			ArrayList<String> line = new ArrayList<String>();
			line.add(book.getIsbn());
			line.add(book.getTitle());
			line.add(book.getTypeName());
			line.add(book.getPrice()+"");
			tableData.add(line);
		}
		
		public String getISDN(int rowIndex){
			ArrayList<String> list = this.tableData.get(rowIndex);
			return list.get(0);
		}
		
		
		public void updateUI(){
			tableData.clear();
			for(BookSpecification book : BookCatalog.getInstance().getBooks()){
				addBook(book);
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
	
	class MainUIObserver implements Observer{
		public void update(){
			ModelTable model = (ModelTable) table.getModel();
			model.updateUI();
		}
	}
	
	private void openShopCartUI(){
		if(shopCartUI == null ){
			shopCartUI = new ShoppingCartUI(this);
			shopCartUI.setVisible(true);
		}
	}
	
	public void closeShopCartUI(){
		shopCartUI = null;
	}
	
	private void initializeUI(){
		
		this.setTitle("ͼ����̹���ƽ̨");
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		
		this.setBounds(100, 100, 625, 400);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JMenuBar menuBar = new JMenuBar();
		this.setJMenuBar(menuBar);
		
		//һ���˵�1,����
		JMenu manage = new JMenu("����");
		manage.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		menuBar.add(manage);
		
		//�����˵�1-1,ͼ�����
		JMenuItem bookManage = new JMenuItem("ͼ�����");
		bookManage.addActionListener((e) -> {
			//��ͼ�����
			BooksManageUI booksUI = new BooksManageUI(this);
			booksUI.setVisible(true);
			this.setEnabled(false);
		});
		manage.add(bookManage);
		
		//�����˵�1-2,���Թ���
		JMenuItem strategyManage = new JMenuItem("���Թ���");
		strategyManage.addActionListener((e) -> {
			//�򿪲��Թ���
			StrategiesUI strategiesUI = new StrategiesUI(this);
			strategiesUI.setVisible(true);
			this.setEnabled(false);
			
		});
		manage.add(strategyManage);
		
		//һ���˵�2,�ҵĹ��ﳵ
		JMenu shopCart = new JMenu("���ﳵ");
		shopCart.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		menuBar.add(shopCart);
		
		//�����˵�2-1,��չ��ﳵ
		JMenuItem clearCart = new JMenuItem("��չ��ﳵ");
		clearCart.addActionListener((e) -> {
			if(JOptionPane.showConfirmDialog(null, "�Ƿ������չ��ﳵ������˼��",
					"clearCart",JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION){
				Controller.getInstance().clearShopCart();
				Controller.getInstance().messageBox("���ﳵ�Ѿ����", "Right");
			}
		});
		shopCart.add(clearCart);
		
		bookSelected = new JLabel("��δѡ���κ�ͼ��");
		bookSelected.setFont(new Font("Microsoft YaHei UI", Font.BOLD, 15));
		bookSelected.setBounds(10, 260, 370, 30);
		this.getContentPane().add(bookSelected);
		
		//ͼ��Ŀ¼����ʼ��
		table = new JTable();
		table.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		
		table.setModel(new ModelTable());
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		DefaultTableCellRenderer tcr = new DefaultTableCellRenderer();
		tcr.setHorizontalAlignment(SwingConstants.CENTER);
		table.setDefaultRenderer(Object.class, tcr);
		table.getTableHeader().setReorderingAllowed(false);
		table.getTableHeader().setResizingAllowed(false);
	    table.getColumnModel().getColumn(0).setPreferredWidth(100);
	    table.getColumnModel().getColumn(1).setPreferredWidth(100);
	    table.getColumnModel().getColumn(2).setPreferredWidth(100);
	    table.getColumnModel().getColumn(3).setPreferredWidth(20);
	    
	    table.getSelectionModel().addListSelectionListener(new ListSelectionListener(){
            public void valueChanged(ListSelectionEvent e) {
            	boolean bl=e.getValueIsAdjusting();
            	if(!bl){
            		int selectedRow = table.getSelectedRow();
            		if (selectedRow < 0){
            			bookSelected.setText("δѡ���κ�ͼ��");
            		}else {
	            		bookSelected.setText("ѡ��ͼ�飺" +
	            			table.getModel().getValueAt(selectedRow, 0) + " ��" +
	            			table.getModel().getValueAt(selectedRow, 1) + "��");
            		}
            	}                
            }
        });
	    
	  //��ʾ���
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 24 , 600, 225);
		this.getContentPane().add(scrollPane);
		scrollPane.setViewportView(table);
	    
	    this.getContentPane().setLayout(null);
	    
	    JLabel label1 = new JLabel("��������");
		label1.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		label1.setBounds(470, 260, 65, 30);
		this.getContentPane().add(label1);
		
		JLabel label2 = new JLabel("��");
		label2.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		label2.setBounds(599, 268, 17, 15);
		this.getContentPane().add(label2);
		
		spinner = new JSpinner();
		spinner.setModel(new SpinnerNumberModel(new Integer(0), new Integer(0), null, new Integer(1)));
		spinner.setBounds(541, 260, 54, 30);
		this.getContentPane().add(spinner);
		
		JButton addToCartButton = new JButton("���빺�ﳵ");
		addToCartButton.addActionListener((e) -> {
			//�����ͼ�������ﳵ
			addToShopCart();
			
		});
		addToCartButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		addToCartButton.setBounds(350, 301, 120, 30);
		this.getContentPane().add(addToCartButton);
		
		JButton watchCartButton = new JButton("�鿴���ﳵ");
		watchCartButton.addActionListener((e) -> {
			//�򿪹��ﳵ�Ի���
			openShopCartUI();
		});
		watchCartButton.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		watchCartButton.setBounds(488, 301, 120, 30);
		this.getContentPane().add(watchCartButton);
		
	}
	
	private void addToShopCart(){
		int selectedRow = table.getSelectedRow();
		int copies = 0;
		copies = (int) spinner.getValue();
		if(selectedRow < 0){
			Controller.getInstance().messageBox("��ѡ��һ��ͼ�飡", "ERROR");
			return;
		}
		if(copies <= 0){
			Controller.getInstance().messageBox("�������ô���", "ERROR");
			return;
		}
		
		String isbn = (String) table.getValueAt(selectedRow, 0);
		
		if(Controller.getInstance().addSaleItem(isbn, copies)){
			Controller.getInstance().messageBox("��� "+copies+"�� ��"+
					BookCatalog.getInstance().getBook(isbn).getTitle()
					+"��", "SUCCESS");
			spinner.setValue(0);
		}
		else{
			Controller.getInstance().messageBox("��Ӵ���", "SUCCESS");
		}
	}
	
	
	
}
