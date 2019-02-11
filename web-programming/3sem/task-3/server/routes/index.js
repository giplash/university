import productsRouter from './products';
import billsRouter from './billsRouter';

export default app => {
  app.use('/api/products', productsRouter);
  app.use('/api/bills', billsRouter);
  app.get('*', (req, res) => {
    res.render('index');
  });
};